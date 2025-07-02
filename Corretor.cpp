#include "Corretor.h"

int Corretor::nextId = 1;

Corretor::Corretor(const std::string& telefone, int avaliador, double lat, double lon, const std::string& nome)
    : telefone(telefone), avaliador(avaliador), lat(lat), lon(lon), nome(nome) {
    id = nextId++;
}
