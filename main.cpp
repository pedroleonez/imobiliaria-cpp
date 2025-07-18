#include <iostream>
#include <vector>
#include "Corretor.h"
#include "Cliente.h"
#include "Imovel.h"
#include "Agendamento.h"

int main() {
    int numCorretores;
    std::cin >> numCorretores;
    std::vector<Corretor> corretores;
    for (int i = 0; i < numCorretores; ++i) {
        std::string telefone; int avaliador; double lat, lon;
        std::string nome;
        std::cin >> telefone >> avaliador >> lat >> lon;
        std::getline(std::cin >> std::ws, nome);
        corretores.emplace_back(telefone, avaliador, lat, lon, nome);
    }

    int numClientes;
    std::cin >> numClientes;
    std::vector<Cliente> clientes;
    for (int i = 0; i < numClientes; ++i) {
        std::string telefone, nome;
        std::cin >> telefone;
        std::getline(std::cin >> std::ws, nome);
        clientes.emplace_back(telefone, nome);
    }

    int numImoveis;
    std::cin >> numImoveis;
    std::vector<Imovel> imoveis;
    for (int i = 0; i < numImoveis; ++i) {
        std::string tipoStr; int propId; double lat, lon, preco;
        std::string endereco;
        std::cin >> tipoStr >> propId >> lat >> lon >> preco;
        std::getline(std::cin >> std::ws, endereco);
        imoveis.emplace_back(tipoStr, propId, lat, lon, preco, endereco);
    }

    gerarAgendamento(corretores, imoveis);
    return 0;
}