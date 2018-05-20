#pragma once
#include "Graph.h"

class Prim
{
public:

	static void PrimSerch_Matrix(Graph * _graph);
	static void PrimSerch_List(Graph * _graph);

	Prim();
	~Prim();
};

