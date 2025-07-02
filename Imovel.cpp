#include "Imovel.h"

int Imovel::nextId = 1;

Imovel::Imovel(const std::string& tipoStr, int propId, double lat, double lon, double preco, const std::string& endereco)
    : proprietarioId(propId), lat(lat), lon(lon), preco(preco), endereco(endereco) {
    id = nextId++;
    if (tipoStr == "Casa") tipo = TipoImovel::Casa;
    else if (tipoStr == "Apartamento") tipo = TipoImovel::Apartamento;
    else tipo = TipoImovel::Terreno;
}