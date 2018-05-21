#pragma once
#include "Graph.h"

class Dijkstra
{

public:
	static void Dijkstra_Matrix(Graph * _graph, int vStart);
	static void Dijkstra_List(Graph * _graph, int vStart);

	Dijkstra();
	~Dijkstra();
};

