#pragma once
#include <string>
#include <list>
#include <vector>

class Graph
{

private:

	int edgeAmount;
	int verticeAmount;
	int **_graphMatrix;
	std::vector<std::list<class Neighbour*>> _graphList;



public:
	int** getGraphMatrix();
	int getEdgeAmount();
	int getVerticeAmount();
	int getWeight(int vertex1, int vertex2);
	std::vector<std::list<class Neighbour*>> getList();

	bool loadFromFile(std::string fileName, bool isDirected);
	void printMatrix();
	void printList();
	Graph();
	~Graph();

};

