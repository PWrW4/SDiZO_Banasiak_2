#include "stdafx.h"
#include "Prim.h"
#include <iostream>


void Prim::PrimSerch_Matrix(Graph * _graph)
{
	if (_graph == nullptr)
	{
		return;
	}

	if (_graph->getVerticeAmount()<=0)
	{
		return;
	}
	

	std::vector<int> edgeDones;
	int currentVerticle = 0;
	edgeDones.push_back(0);	
	int valToAdd;
	do
	{
		int lowest_val = INT32_MAX;
		
		for (int curr_edge : edgeDones)
		{
			for (int i = 0; i<_graph->getEdgeAmount(); i++)
			{
				if (_graph->getGraphMatrix()[curr_edge][i]>0)
				{
					if (_graph->getGraphMatrix()[curr_edge][i]<lowest_val)
					{
						for (int y = 0; y<_graph->getVerticeAmount(); y++)
						{
							if (_graph->getGraphMatrix()[y][i] != 0 && y!=curr_edge)
							{
								bool canAdd = true;
								for (int done : edgeDones)
								{
									if (done==y)
									{
										canAdd = false;
									}
								}
								if (canAdd)
								{
									valToAdd = y;
									lowest_val = _graph->getGraphMatrix()[y][i];
								}

							}
						}

					}
				}
			}
		}



		edgeDones.push_back(valToAdd);
	}
	while (edgeDones.size()!=_graph->getVerticeAmount());
	
	std::cout << "Wynik:" << std::endl;
	
	for (int done : edgeDones)
	{		
		std::cout << done <<" ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
}

void Prim::PrimSerch_List(Graph * _graph)
{

	if (_graph->getVerticeAmount() <= 0)
	{
		return;
	}


	std::vector<int> edgeDones;
	int currentVerticle = 0;
	edgeDones.push_back(0);
	int valToAdd;
	
	do
	{
		int lowest_val = INT32_MAX;

		for (int curr_edge : edgeDones)
		{
			std::list<Neighbour*>::iterator j;

			for (j = _graph->getList()[curr_edge].begin() ; j = _graph->getList()[curr_edge];)
			{
				if (_graph->getList()[curr_edge][i]>0)
				{
					if (_graph->getGraphMatrix()[curr_edge][i]<lowest_val)
					{
						for (int y = 0; y<_graph->getVerticeAmount(); y++)
						{
							if (_graph->getGraphMatrix()[y][i] != 0 && y != curr_edge)
							{
								bool canAdd = true;
								for (int done : edgeDones)
								{
									if (done == y)
									{
										canAdd = false;
									}
								}
								if (canAdd)
								{
									valToAdd = y;
									lowest_val = _graph->getGraphMatrix()[y][i];
								}

							}
						}

					}
				}
				j++;
			}
		}



		edgeDones.push_back(valToAdd);
	} while (edgeDones.size() != _graph->getVerticeAmount());

	std::cout << "Wynik:" << std::endl;

	for (int done : edgeDones)
	{
		std::cout << done << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
}

Prim::Prim()
{
}


Prim::~Prim()
{
}
