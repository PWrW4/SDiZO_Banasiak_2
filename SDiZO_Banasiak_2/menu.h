#pragma once
#include <string>

class menu
{
private:
	std::string mainMenuStr = " 1. Wczytaj dane z pliku.	\n 2. Wygeneruj graf losowo. \n 3. Wyświetl graf listowo i macierzowo na ekranie. \n 4. Algorytm 1 \n 5. Algorytm 2";


	void mainMenu();

public:
	menu();
	~menu();
};

