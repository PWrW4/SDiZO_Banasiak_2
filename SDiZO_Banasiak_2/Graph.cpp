#include "stdafx.h"
#include "Graph.h"
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Neighbour.h"

int ** Graph::getGraphMatrix()
{
	return _graphMatrix;
}

int Graph::getEdgeAmount()
{
	return edgeAmount;
}

int Graph::getVerticeAmount()
{
	return verticeAmount;
}


int Graph::getWeight(int vertex1, int vertex2)
{
	return _graphMatrix[vertex1][vertex2];
}

std::vector<std::list<class Neighbour*>> Graph::getList()
{
	return _graphList;
}

std::vector<std::list<class Neighbour*>> * Graph::getListP()
{
	return &_graphList;
}

bool Graph::loadFromFile(std::string fileName, bool isDirected)
{
	//Macierz------------------------------------------------------------------------------------------------------------
	std::fstream file;
	file.open(fileName, std::ios::in);
	if (file.is_open())
	{
		if (file.fail())
		{
			return false;
		}
		file >> edgeAmount;
		file >> verticeAmount;
		_graphMatrix = new int *[verticeAmount];	//Przydzielam pamiêæ na wiersze
		for (int i = 0; i < verticeAmount; i++)
		{
			_graphMatrix[i] = new int[edgeAmount];
		}

		for (int i = 0; i < verticeAmount; i++)
		{
			for (int j = 0; j < edgeAmount; j++)
			{
				_graphMatrix[i][j] = 0;	//wypelniam macierz nieskonczonoscia
											
			}
		}

		int tempVertex1, tempVertex2, weight;

		for (int i = 0; i < edgeAmount; i++)
		{


			file >> tempVertex1;
			file >> tempVertex2;
			file >> weight;

			if (file.fail())
			{
				return false;
			}


			_graphMatrix[tempVertex1][i] = weight;
			

			if (isDirected)
			{
				_graphMatrix[tempVertex2][i] = (-1)*weight;
			}
			else
			{
				_graphMatrix[tempVertex2][i] = weight;
			}

			tempVertex1 = 0; tempVertex2 = 0; weight = 0;
		}

		file.close();

		//Lista----------------------------------------------------------------------------------------------------
		
		//Czyszczenie listy przy wielokrotnym wczytywaniu
		for (int i = 0; i < _graphList.size(); i++)
		{
			std::list<Neighbour*>::iterator start,end;

			start = _graphList[i].begin();
			end = _graphList[i].end();
			
			_graphList[i].erase(start, end);
		}

		file.open(fileName, std::ios::in);

		int edge[3]; //Informacje o krawêdzi do pêtli edge[0] - wierzcho³ek pocz¹tkowy, edge[1] - koñcowy, edge[2] - waga
		Neighbour *tempNeighbour; //Tymczasowy wierzcho³ek s¹siaduj¹cy umieszczany na liœcie

		if (file.is_open())
		{
			if (file.fail())
			{
				return false;
			}
			file >> edgeAmount;
			file >> verticeAmount;

			_graphList.resize(verticeAmount);

			for (int i = 0; i < edgeAmount; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					file >> edge[j];
				}

				tempNeighbour = new Neighbour(edge[2], edge[1]);
				_graphList[edge[0]].push_front(tempNeighbour);
				//	delete tempNeighbour;
				if (!isDirected)
				{
					tempNeighbour = new Neighbour(edge[2], edge[0]);
					_graphList[edge[1]].push_front(tempNeighbour);
					//delete tempNeighbour;
				}

			}


			file.close();
		}



		return true;
	}
	else
	{
		std::cout << "Plik nie zostal otwarty, nastapi wyjscie do menu glownego." << std::endl;

	}
	return false;
}

void Graph::printMatrix()
{


	std::cout << std::setw(4) << "  ";
	for (int i = 0; i < edgeAmount; i++)
	{
		std::cout << std::setw(3) << " | " << std::setw(3) << i;
	}
	std::cout << std::setw(3) << " | " << std::endl;
	for (int i = 0; i < verticeAmount; i++)
	{
		std::cout << i << std::setw(3) << "|";
		for (int j = 0; j < edgeAmount; j++)
		{
			if (_graphMatrix[i][j] != 0 && _graphMatrix[i][j] != 0)
			{
				std::cout << std::setw(3) << " : " << std::setw(3) << _graphMatrix[i][j];
			}
			else std::cout << std::setw(3) << " : " << std::setw(3) << "---";
		}
		std::cout << std::setw(3) << " : " << std::endl;
	}
}

void Graph::printList()
{
	std::cout << " Wierzcholek:" << " S - Sasiad W - Waga." << std::endl;
	std::list<Neighbour*>::const_iterator j;
	for (int i = 0; i < verticeAmount; i++)
	{
		std::cout << i << ": ";
		std::list<Neighbour*>::iterator j;

		for (j = _graphList[i].begin(); j != _graphList[i].end();)
		{
			(*j)->print();
			++j;
		}
		std::cout << std::endl;
	}
}

Graph::Graph()
{
	verticeAmount = 0;
	edgeAmount = 0;
	_graphMatrix = nullptr;
}


Graph::~Graph() //Po dodaniu reprezentacji listowej
{
	for (int i = 0; i < verticeAmount; i++)	//Zwalnianie pamiêci zajêtej przez macierz
	{
		delete[] _graphMatrix[i];
	}
	delete[] _graphMatrix;
}

