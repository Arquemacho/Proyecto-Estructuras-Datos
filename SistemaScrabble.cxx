// SistemaScrabble.cxx
#include "SistemaScrabble.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

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

std::vector<std::string> dividirComando(const std::string& comando) {
	std::vector<std::string> resultado;
	std::stringstream ss(comando);
	std::string item;
	while (std::getline(ss, item, ' ')) {
		resultado.push_back(item);
	}
	return resultado;
}

void SistemaScrabble::procesarComando(const std::string& comando) {
	auto palabras = dividirComando(comando);
	if (palabras.empty()) return; // Si el comando está vacío, no hacemos nada

	if (palabras[0] == "ayuda") {
		ayuda();
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

void SistemaScrabble::ayuda() {
	std::cout << "Comandos disponibles:\n";
	std::cout << "  ayuda                      - Muestra esta lista de comandos.\n";
	std::cout << "  inicializar <archivo>      - Inicializa el diccionario con el archivo dado.\n";
	std::cout << "  iniciar_inverso <archivo>  - Inicializa el diccionario inverso con el archivo dado.\n";
	std::cout << "  puntaje <palabra>          - Calcula el puntaje de una palabra dada.\n";
	std::cout << "  salir                      - Sale del programa.\n";
}

void SistemaScrabble::inicializarDiccionario(const std::string& archivo) {
	std::cout << "Inicializando diccionario desde " << archivo << "\n";
	// Aquí iría la lógica para cargar el diccionario
}

void SistemaScrabble::iniciarDiccionarioInverso(const std::string& archivo) {
	std::cout << "Inicializando diccionario inverso desde " << archivo << "\n";
	// Aquí iría la lógica para cargar el diccionario inverso
}

void SistemaScrabble::puntajePalabra(const std::string& palabra) {
	std::cout << "Calculando puntaje para la palabra: " << palabra << "\n";
	// Aquí iría la lógica para calcular el puntaje de la palabra
}

void SistemaScrabble::salir() {
    std::cout << "Saliendo del sistema...\n";
    exit(0); // Termina la ejecución del programa
}

