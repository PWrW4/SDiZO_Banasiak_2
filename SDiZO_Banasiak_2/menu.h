#pragma once
#include <string>
#include "Graph.h"
#include "GGenerator.h"

class menu
{
private:
	std::string mainMenuStr = " 1. Wczytaj dane z pliku. \n 2. Wygeneruj graf losowo. \n 3. Wyswietl graf listowo lub macierzowo na ekranie. \n 4. Algorytm 1 \n 5. Algorytm 2";

	Graph * _graph = nullptr;

	void mainMenu();

public:
	menu();
	~menu();
};

