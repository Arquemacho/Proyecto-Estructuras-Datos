#include "SistemaScrabble.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

SistemaScrabble::SistemaScrabble() {
    // Constructor para inicializar lo que necesitamos ;)
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
std::vector<std::string> SistemaScrabble::dividirComando(const std::string& comando) {
    std::vector<std::string> resultado;
    std::istringstream iss(comando);
    std::string palabra;
    while (iss >> palabra) {
        resultado.push_back(palabra);
    }
    return resultado;
}


void SistemaScrabble::procesarComando(const std::string& comandoEntrada) {
    auto palabras = dividirComando(comandoEntrada);
    if (palabras.empty()) return; 

    if (palabras[0] == "ayuda") {
        ayuda(palabras);
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
    } 
    else if (palabras[0] == "iniciar_arbol") {
        if (palabras.size() < 2) {
            std::cout << "Uso: iniciar_arbol <archivo_diccionario.txt>\n";
        } else {
            iniciarArbol(palabras[1]);
        }
    } else if (palabras[0] == "iniciar_arbol_inverso") {
        if (palabras.size() < 2) {
            std::cout << "Uso: iniciar_arbol_inverso <archivo_diccionario.txt>\n";
        } else {
            iniciarArbolInverso(palabras[1]);
        }
    } else if (palabras[0] == "palabras_por_prefijo") {
        if (palabras.size() < 2) {
            std::cout << "Uso: palabras_por_prefijo <prefijo>\n";
        } else {
            palabrasPorPrefijo(palabras[1]);
        }
    } else if (palabras[0] == "palabras_por_sufijo") {
        if (palabras.size() < 2) {
            std::cout << "Uso: palabras_por_sufijo <sufijo>\n";
        } else {
            palabrasPorSufijo(palabras[1]);
        }
    } else if (palabras[0] == "grafo_de_palabras") {
        grafoDePalabras();
    } else if (palabras[0] == "posibles_palabras") {
        if (palabras.size() < 2) {
            std::cout << "Uso: posibles_palabras <letras>\n";
        } else {
            posiblesPalabras(palabras[1]);
        }
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
        const std::string& comando = args[1];
        if (comando == "inicializar") {
            std::cout << "Uso: inicializar <archivo_diccionario.txt> - Inicializa el diccionario con el archivo dado.\n";
        } else if (comando == "iniciar_inverso") {
            std::cout << "Uso: iniciar_inverso <archivo_diccionario.txt> - Inicializa el diccionario inverso con el archivo dado.\n";
        } else if (comando == "puntaje") {
            std::cout << "Uso: puntaje <palabra> - Calcula el puntaje de una palabra dada.\n";
        } else if (comando == "salir") {
            std::cout << "Uso: salir - Sale del programa.\n";
        } 
        else if (comando == "iniciar_arbol") {
            std::cout << "Uso: iniciar_arbol <archivo_diccionario.txt> - Inicializa el árbol del diccionario con el archivo dado.\n";
        } else if (comando == "iniciar_arbol_inverso") {
            std::cout << "Uso: iniciar_arbol_inverso <archivo_diccionario.txt> - Inicializa el árbol del diccionario inverso con el archivo dado.\n";
        } else if (comando == "palabras_por_prefijo") {
            std::cout << "Uso: palabras_por_prefijo <prefijo> - Muestra palabras que inician con el prefijo dado.\n";
        } else if (comando == "palabras_por_sufijo") {
            std::cout << "Uso: palabras_por_sufijo <sufijo> - Muestra palabras que terminan con el sufijo dado.\n";
        } else if (comando == "grafo_de_palabras") {
            std::cout << "Uso: grafo_de_palabras - Construye un grafo de palabras donde cada palabra se conecta a las demás si difieren en una única letra.\n";
        } else if (comando == "posibles_palabras") {
            std::cout << "Uso: posibles_palabras <letras> - Muestra posibles palabras a construir con las letras dadas.\n";
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
  std::cout << "(Resultado exitoso) Se creo el diccionario inverso je ...\n";
}

void SistemaScrabble::puntajePalabra(const std::string& palabra) {
  std::cout << "(Resultado exitoso) El puntaje de tu palabra es infinito :) ...\n";
}

void SistemaScrabble::salir() {
    std::cout << "Saliendo del sistema...\n";
    exit(0);
}

void SistemaScrabble::iniciarArbol(const std::string &archivo) {
    std::cout << "(Resultado exitoso) El árbol del diccionario se ha inicializado correctamente.\n";
}

void SistemaScrabble::iniciarArbolInverso(const std::string &archivo) {
    std::cout << "(Resultado exitoso) El árbol del diccionario inverso se ha inicializado correctamente.\n";
}

void SistemaScrabble::palabrasPorPrefijo(const std::string &prefijo) {
    std::cout << "(Resultado exitoso) Las palabras que inician con este prefijo son: ...\n";
}

void SistemaScrabble::palabrasPorSufijo(const std::string &sufijo) {
    std::cout << "(Resultado exitoso) Las palabras que terminan con este sufijo son: ...\n";
}

void SistemaScrabble::grafoDePalabras() {
    std::cout << "(Resultado exitoso) Grafo construido correctamente.\n";
}

void SistemaScrabble::posiblesPalabras(const std::string &letras) {
    std::cout << "(Resultado exitoso) Las posibles palabras a construir con las letras " << letras << " son: ...\n";
}
