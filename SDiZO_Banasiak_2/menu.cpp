#include "stdafx.h"
#include "menu.h"
#include <iostream>
#include "Prim.h"
#include "Dijkstra.h"
#include <ctime>
#include <windows.h>


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
				std::cout << "zly wybor xD" << std::endl;
				break;
			}
			
			break;
		case 4:
			std::cout << "1. Listowo \n2. Macierzowo" << std::endl;
			std::cin >> decision;
			switch (decision)
			{
			case 1:
				Prim::PrimSerch_List(_graph,1);
				break;
			case 2:
				Prim::PrimSerch_Matrix(_graph,1);
				break;
			default:
				std::cout << "zly wybor xD"<<std::endl;
				break;
			}
			break;
		case 5:
			std::cout << "1. Listowo \n2. Macierzowo" << std::endl;
			std::cin >> decision;
			std::cout << "Podaj startowy wierzcholek" << std::endl;
			std::cin >> startVal;
			switch (decision)
			{
			case 1:
				Dijkstra::Dijkstra_List(_graph,startVal,1);
				break;
			case 2:
				Dijkstra::Dijkstra_Matrix(_graph, startVal,1);
				break;
			default:
				std::cout << "zly wybor xD" << std::endl;
				break;
			}
			break;
		case 6:
			srand(time(NULL));

			double List = 0;
			double Matrix = 0;

			std::cout << "1. Prim \n2. Dijkstra" << std::endl;
			switch (decision)
			{
			case 1:
				for (int i=0;i<100;i++)
				{
					StartCounter();
					Prim::PrimSerch_List(_graph, 0);
					List += GetCounter();
					StartCounter();
					Prim::PrimSerch_Matrix(_graph, 0);
					Matrix += GetCounter();
				}
				
				break;
			case 2:
				for (int i = 0; i<100; i++)
				{
					startVal = rand() % _graph->getVerticeAmount();
					StartCounter();
					Dijkstra::Dijkstra_List(_graph, startVal, 0);
					List += GetCounter();
					StartCounter();
					Dijkstra::Dijkstra_Matrix(_graph, startVal, 0);
					Matrix += GetCounter();
				}
				break;
			default:
				std::cout << "zly wybor xD" << std::endl;
				break;
			}

			std::cout << std::endl<<"List: "<<List<<std::endl<<"Matrix: "<<Matrix<<std::endl;

			break;
		default:
			std::cout << "zly wybor xD" << std::endl;
			break;
		}
	}
	while (decision);

}

void menu::StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		std::cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

double menu::GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}


menu::menu()
{
	_graph = new Graph;
	mainMenu();
}


menu::~menu()
{
}
