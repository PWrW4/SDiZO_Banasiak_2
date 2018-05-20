#include "stdafx.h"
#include "menu.h"
#include <iostream>
#include "Prim.h"


void menu::mainMenu()
{
	int decision = 0;
	int directed = 1;
	int verticle = 1;
	float density = 1;
	int rangeVal = 1;
	int startVal = 1;
	std::string fname = "";

	do
	{
		std::cout<<mainMenuStr<<std::endl;
		std::cin >> decision;
		switch (decision)
		{
		case 1:
			std::cout << "Podaj nazwe pliku"<<std::endl;
			std::cin >> fname;
			std::cout << "Graf skierowany? 1-tak, 0-nie" << std::endl;
			std::cin >> directed;
			_graph->loadFromFile(fname, directed);
			break;
		case 2:
			std::cout << "Podaj: ilosc wierzcholkow, wypelnienie (w %), skierowany? (1-tak, 0-nie),rozmiar kosztow, najmniejsza wartosc kosztow, nazwe pliku." <<std::endl;
			std::cin >> verticle;
			std::cin >> density;
			std::cin >> directed;
			std::cin >> rangeVal;
			std::cin >> startVal;
			std::cin >> fname;
			GGenerator::generateGraph(verticle, density, directed, rangeVal, startVal, fname);
			_graph->loadFromFile(fname+".txt", directed);
			break;
		case 3:
			std::cout << "1. Listowo \n2. Macierzowo" << std::endl;
			std::cin >> decision;
			switch (decision)
			{
			case 1:
				_graph->printList();
				break;
			case 2:
				_graph->printMatrix();
				break;
			default:
				std::cout << "zly wybor xD";
				break;
			}
			
			break;
		case 4:
			std::cout << "1. Listowo \n2. Macierzowo" << std::endl;
			std::cin >> decision;
			switch (decision)
			{
			case 1:
				Prim::PrimSerch_List(_graph);
				break;
			case 2:
				Prim::PrimSerch_Matrix(_graph);
				break;
			default:
				std::cout << "zly wybor xD";
				break;
			}
			break;
		case 5:
			break;
		default:
			std::cout << "zly wybor xD";
			break;
		}
	}
	while (decision);

}

menu::menu()
{
	_graph = new Graph;
	mainMenu();
}


menu::~menu()
{
}
