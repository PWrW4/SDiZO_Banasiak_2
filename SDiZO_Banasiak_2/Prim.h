#pragma once
#include "Graph.h"

class Prim
{
public:

	static void PrimSerch_Matrix(Graph * _graph, int print);
	static void PrimSerch_List(Graph * _graph, int print);

	Prim();
	~Prim();
};

