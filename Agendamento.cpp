#include "Agendamento.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <algorithm>

constexpr double EARTH_R = 6371.0;
double haversine(double lat1, double lon1, double lat2, double lon2) {
    auto deg2rad = [](double d){ return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat/2), 2) +
               std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
               std::pow(std::sin(dlon/2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}

void gerarAgendamento(std::vector<Corretor>& corretores, std::vector<Imovel>& imoveis) {
    std::vector<Corretor*> avaliadores;
    for (auto& c : corretores)
        if (c.avaliador) avaliadores.push_back(&c);

    std::sort(imoveis.begin(), imoveis.end(), [](const Imovel& a, const Imovel& b){ return a.id < b.id; });

    std::map<int, std::vector<Imovel>> agendas;
    for (size_t i = 0; i < imoveis.size(); ++i)
        agendas[avaliadores[i % avaliadores.size()]->id].push_back(imoveis[i]);

    for (size_t idx = 0; idx < avaliadores.size(); ++idx) {
        auto* c = avaliadores[idx];
        double curLat = c->lat, curLon = c->lon;
        int hora = 9, minuto = 0;
        std::vector<Imovel> agenda = agendas[c->id];
        std::vector<bool> visitado(agenda.size(), false);

        std::cout << "Corretor " << c->id << "\n";

        for (size_t count = 0; count < agenda.size(); ++count) {
            int prox = -1;
            double minDist = 1e9;
            for (size_t i = 0; i < agenda.size(); ++i) {
                if (!visitado[i]) {
                    double d = haversine(curLat, curLon, agenda[i].lat, agenda[i].lon);
                    if (d < minDist) {
                        minDist = d;
                        prox = i;
                    }
                }
            }

            double tempoDesloc = minDist * 2;
            int totalMin = minuto + static_cast<int>(tempoDesloc);
            hora += totalMin / 60;
            minuto = totalMin % 60;

            std::cout << std::setfill('0') << std::setw(2) << hora << ":" << std::setw(2) << minuto
                      << " Imóvel " << agenda[prox].id;
            
            // Imprimir quebra de linha apenas se não for a última linha do último corretor
            if (idx < avaliadores.size() - 1 || count < agenda.size() - 1) {
                std::cout << "\n";
            }

            totalMin = minuto + 60;
            hora += totalMin / 60;
            minuto = totalMin % 60;
            curLat = agenda[prox].lat;
            curLon = agenda[prox].lon;
            visitado[prox] = true;
        }

        // Adicionar linha em branco apenas se não for o último corretor
        if (idx < avaliadores.size() - 1) {
            std::cout << "\n";
        }
    }
}