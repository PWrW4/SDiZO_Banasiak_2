#pragma once
#include <string>
#include "Graph.h"
#include "GGenerator.h"

class menu
{
private:
	std::string mainMenuStr = " 1. Wczytaj dane z pliku. \n 2. Wygeneruj graf losowo. \n 3. Wyswietl graf listowo lub macierzowo na ekranie. \n 4. Algorytm Prima \n 5. Algorytm Dijkstry \n 6. Testy!!!";

	Graph * _graph = nullptr;

	double PCFreq = 0.0;
	__int64 CounterStart = 0;

	void StartCounter();
	double GetCounter();

	void mainMenu();

public:
	menu();
	~menu();
};

