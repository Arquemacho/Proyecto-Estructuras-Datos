// SistemaScrabble.cxx
#include "SistemaScrabble.h"
#include <iostream>
#include <fstream>
#include <unordered_set>

SistemaScrabble::SistemaScrabble() {
    // Constructor para inicializar lo necesario
}

void SistemaScrabble::ejecutar() {
    std::string comando;
    std::cout << "Sistema de apoyo para Scrabble\n";
    while (true) {
        std::cout << "$ ";
        std::getline(std::cin, comando);
        procesarComando(comando);
        if (comando == "salir") break;
    }
}

void SistemaScrabble::procesarComando(const std::string& comando) {
    // Implementa la lógica para procesar cada comando aquí
}

// Aquí irían las implementaciones de los métodos declarados...
