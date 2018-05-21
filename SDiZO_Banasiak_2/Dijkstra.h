#pragma once
#include "Graph.h"

class Dijkstra
{

public:
	static void Dijkstra_Matrix(Graph * _graph, int vStart, int print);
	static void Dijkstra_List(Graph * _graph, int vStart, int print);

	Dijkstra();
	~Dijkstra();
};

