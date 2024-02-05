#ifndef SISTEMA_SCRABBLE_H
#define SISTEMA_SCRABBLE_H

#include <string>
#include <unordered_set>

class SistemaScrabble {
public:
    SistemaScrabble();
    void ejecutar();

private:
    std::unordered_set<std::string> diccionario;
    std::unordered_set<std::string> diccionarioInverso;

    void procesarComando(const std::string& comando);
    void ayuda();
    void inicializarDiccionario(const std::string& archivo);
    void iniciarDiccionarioInverso(const std::string& archivo);
    void puntajePalabra(const std::string& palabra);
    void salir();
    bool esValidaLaPalabra(const std::string& palabra);
};

#endif // SISTEMA_SCRABBLE_H
