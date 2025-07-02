#include "Cliente.h"

int Cliente::nextId = 1;

Cliente::Cliente(const std::string& telefone, const std::string& nome)
    : telefone(telefone), nome(nome) {
    id = nextId++;
}