// SistemaScrabble.h
#ifndef SISTEMA_SCRABBLE_H
#define SISTEMA_SCRABBLE_H

#include <string>

class SistemaScrabble {
public:
    SistemaScrabble();
    void ejecutar();
private:
    void inicializarDiccionario(const std::string& archivo);
    void iniciarDiccionarioInverso(const std::string& archivo);
    void puntajePalabra(const std::string& palabra);
    void salir();
    void procesarComando(const std::string& comando);
    void ayuda();
};

#endif // SISTEMA_SCRABBLE_H
