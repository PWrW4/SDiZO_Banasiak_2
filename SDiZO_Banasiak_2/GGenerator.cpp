#include "stdafx.h"
#include "GGenerator.h"
#include <ctime>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#define INF INT_MAX

void GGenerator::generateGraph(int verticeAmount, float density, bool isDirected, int valueRange, int startValue, std::string fileName)
{
	srand(time(NULL));
	
	std::vector<int> connectedVertice(0);	//Wierzcho³ki po³¹czone
	std::vector<int> freeVertice(verticeAmount); //Wierzcho³ki niepo³¹czone
	int** graphMatrix = new int*[verticeAmount];

	for (int i = 0; i < verticeAmount; i++)
	{
		freeVertice[i] = i;
		graphMatrix[i] = new int[verticeAmount];
		for (int j = 0; j < verticeAmount; j++)
			graphMatrix[i][j] = INF;
	}

	int v1;
	int v2;
	int value;
	int counter = 0;
	float wanted = (density / 100)*((verticeAmount*verticeAmount) - verticeAmount);

	v1 = (rand() % freeVertice.size()) + 0;
	connectedVertice.push_back(freeVertice[v1]);
	freeVertice.erase(freeVertice.begin() + v1);


	while (freeVertice.size() != 0)
	{
		v1 = (rand() % connectedVertice.size()) + 0;
		v2 = (rand() % freeVertice.size()) + 0;
		value = (rand() % valueRange) + startValue;
		if (isDirected == false)
		{
			graphMatrix[freeVertice[v2]][connectedVertice[v1]] = value;
			counter++;
		}
		graphMatrix[connectedVertice[v1]][freeVertice[v2]] = value;
		counter++;
		connectedVertice.push_back(freeVertice[v2]);
		freeVertice.erase(freeVertice.begin() + v2);

	}
	if (wanted > (verticeAmount*verticeAmount) - verticeAmount)
		wanted = (verticeAmount*verticeAmount) - verticeAmount;
	while (counter < wanted)
	{
		value = (rand() % valueRange) + startValue;
		v1 = (rand() % verticeAmount) + 0;
		v2 = (rand() % verticeAmount) + 0;

		if (v2 != v1 && graphMatrix[connectedVertice[v1]][connectedVertice[v2]] == INF && value != 0)
		{
			if (isDirected == false)
			{
				graphMatrix[connectedVertice[v2]][connectedVertice[v1]] = value;
				counter++;
			}
			graphMatrix[connectedVertice[v1]][connectedVertice[v2]] = value;
			counter++;
		}

	}


	std::string buffer;
	buffer.append(fileName);
	buffer.append(".txt");
	std::ofstream graph_file;
	graph_file.open(buffer);


	if (isDirected == true)
	{
		graph_file << counter << " " << verticeAmount << "\n";
		for (int i = 0; i < verticeAmount; i++)
			for (int j = 0; j < verticeAmount; j++)
				if (graphMatrix[i][j] != INF)
					graph_file << i << " " << j << " " << graphMatrix[i][j] << "\n";
	}
	else
	{
		int j = 0;
		int k = 0;
		counter = counter / 2;
		graph_file << counter << " " << verticeAmount << "\n";
		for (int i = 0; i < verticeAmount; i++)
		{
			for (j = 0 + k; j < verticeAmount; j++)
				if (graphMatrix[i][j] != INF)
				{
					graph_file << i << " " << j << " " << graphMatrix[i][j] << "\n";

				}
			k++;
		}

	}

	graph_file.close();

	std::cout << "Otrzymany graf: " << std::endl << std::endl;
	std::cout << std::setw(4) << "  ";
	for (int i = 0; i < verticeAmount; i++)
	{
		std::cout << std::setw(3) << " | " << std::setw(3) << i;
	}
	std::cout << std::setw(3) << " | " << std::endl;
	for (int i = 0; i < verticeAmount; i++)
	{
		std::cout << i << std::setw(3) << "|";
		for (int j = 0; j < verticeAmount; j++)
		{
			if (graphMatrix[i][j] != INF)
			{
				std::cout << std::setw(3) << " : " << std::setw(3) << graphMatrix[i][j];
			}
			else std::cout << std::setw(3) << " : " << std::setw(3) << "---";
		}
		std::cout << std::setw(3) << " : " << std::endl;
	}

}

GGenerator::GGenerator()
{
}

GGenerator::~GGenerator()
{
}
