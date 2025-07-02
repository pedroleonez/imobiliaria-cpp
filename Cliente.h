#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
public:
    static int nextId;
    int id;
    std::string telefone;
    std::string nome;

    Cliente(const std::string& telefone, const std::string& nome);
};

#endif