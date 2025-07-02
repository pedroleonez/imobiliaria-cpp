#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>

enum class TipoImovel { Casa, Apartamento, Terreno };

class Imovel {
public:
    static int nextId;
    int id;
    TipoImovel tipo;
    int proprietarioId;
    double lat, lon;
    std::string endereco;
    double preco;

    Imovel(const std::string& tipoStr, int propId, double lat, double lon, double preco, const std::string& endereco);
};

#endif