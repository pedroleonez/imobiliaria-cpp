#ifndef CORRETOR_H
#define CORRETOR_H

#include <string>

class Corretor {
public:
    static int nextId;
    int id;
    std::string telefone;
    bool avaliador;
    double lat, lon;
    std::string nome;

    Corretor(const std::string& telefone, int avaliador, double lat, double lon, const std::string& nome);
};

#endif