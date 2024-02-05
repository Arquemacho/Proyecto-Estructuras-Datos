#include "SistemaScrabble.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

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

void SistemaScrabble::procesarComando(const std::string& comandoEntrada) {
    auto palabras = dividirComando(comandoEntrada);
    if (palabras.empty()) return; // Si el comando está vacío, no hacemos nada

    if (palabras[0] == "ayuda") {
        ayuda(palabras); // Pasamos el vector palabras como argumento
    } else if (palabras[0] == "inicializar") {
        if (palabras.size() < 2) {
            std::cout << "Uso: inicializar <archivo_diccionario.txt>\n";
        } else {
            inicializarDiccionario(palabras[1]);
        }
    } else if (palabras[0] == "iniciar_inverso") {
        if (palabras.size() < 2) {
            std::cout << "Uso: iniciar_inverso <archivo_diccionario.txt>\n";
        } else {
            iniciarDiccionarioInverso(palabras[1]);
        }
    } else if (palabras[0] == "puntaje") {
        if (palabras.size() < 2) {
            std::cout << "Uso: puntaje <palabra>\n";
        } else {
            puntajePalabra(palabras[1]);
        }
    } else if (palabras[0] == "salir") {
        salir();
    } else {
        std::cout << "Comando no reconocido. Use 'ayuda' para ver los comandos disponibles.\n";
    }
}

void SistemaScrabble::ayuda(const std::vector<std::string>& args) {
    if (args.size() == 1) {
        std::cout << "Comandos disponibles:\n";
        std::cout << "  ayuda [comando]            - Muestra información de uso sobre [comando], o esta lista de comandos si no se especifica uno.\n";
        std::cout << "  inicializar <archivo>      - Inicializa el diccionario con el archivo dado.\n";
        std::cout << "  iniciar_inverso <archivo>  - Inicializa el diccionario inverso con el archivo dado.\n";
        std::cout << "  puntaje <palabra>          - Calcula el puntaje de una palabra dada.\n";
        std::cout << "  salir                      - Sale del programa.\n";
    } else {
        // Proporcionar ayuda específica basada en el comando solicitado
        const std::string& comando = args[1];
        if (comando == "inicializar") {
            std::cout << "Uso: inicializar <archivo_diccionario.txt> - Inicializa el diccionario con el archivo dado.\n";
        } else if (comando == "iniciar_inverso") {
            std::cout << "Uso: iniciar_inverso <archivo_diccionario.txt> - Inicializa el diccionario inverso con el archivo dado.\n";
        } else if (comando == "puntaje") {
            std::cout << "Uso: puntaje <palabra> - Calcula el puntaje de una palabra dada.\n";
        } else if (comando == "salir") {
            std::cout << "Uso: salir - Sale del programa.\n";
        } else {
            std::cout << "Comando no reconocido. Use 'ayuda' para ver los comandos disponibles.\n";
        }
    }
}

bool SistemaScrabble::esValidaLaPalabra(const std::string& palabra) {
    return std::all_of(palabra.begin(), palabra.end(), [](char c) { return std::isalpha(c); });
}

void SistemaScrabble::inicializarDiccionario(const std::string& archivo) {
    std::ifstream file(archivo);
    if (!file) {
        std::cout << "(Archivo no existe) El archivo " << archivo << " no existe o no puede ser leído.\n";
        return;
    }
    diccionario.clear();
    std::string palabra;
    while (std::getline(file, palabra)) {
        std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
        if (esValidaLaPalabra(palabra)) diccionario.insert(palabra);
    }
    std::cout << "(Resultado exitoso) El diccionario se ha inicializado correctamente.\n";
}

void SistemaScrabble::iniciarDiccionarioInverso(const std::string& archivo) {
    // La implementación es similar a `inicializarDiccionario`, invirtiendo cada palabra válida antes de insertarla.
}

void SistemaScrabble::puntajePalabra(const std::string& palabra) {
    // Este método necesitará revisión una vez que la funcionalidad de puntuación esté implementada.
}

void SistemaScrabble::salir() {
    std::cout << "Saliendo del sistema...\n";
    exit(0);
}
