#include "stdafx.h"
#include "Prim.h"
#include <iostream>
#include "Neighbour.h"

void Prim::PrimSerch_Matrix(Graph * _graph, int print)
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
	std::vector<int> edgeFolowing;
	int edgeD = 0;
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
									edgeD = y;
									valToAdd = curr_edge;
									lowest_val = _graph->getGraphMatrix()[y][i];
								}

							}
						}

					}
				}
			}
		}



		edgeDones.push_back(edgeD);
		edgeFolowing.push_back(valToAdd);
	}
	while (edgeDones.size()!=_graph->getVerticeAmount());
	
	if (print)
	{
		std::cout << "Wynik:" << std::endl;

		for (int i = 0; i<edgeFolowing.size(); i++)
		{
			std::cout << edgeDones[i + 1] << "-";
			std::cout << edgeFolowing[i] << std::endl;
		}

		std::cout << std::endl;
		std::cout << std::endl;
	}
}

void Prim::PrimSerch_List(Graph * _graph, int print)
{

	if (_graph == nullptr)
	{
		return;
	}

	if (_graph->getVerticeAmount() <= 0)
	{
		return;
	}


	std::vector<int> edgeDones;
	std::vector<int> edgeFolowing;
	int edgeD = 0;
	edgeDones.push_back(0);
	int valToAdd;
	std::vector<std::list<class Neighbour*>>  tmpList = _graph->getList();

	do
	{
		int lowest_val = INT32_MAX;

		for (int curr_edge : edgeDones)
		{
			if (_graph->getList()[curr_edge].size() > 0)
			{
				std::list<Neighbour*>::iterator j;
				for (j = tmpList[curr_edge].begin(); j != tmpList[curr_edge].end();)
				{

					if ((*j)->getWeight() < lowest_val)
					{
						
						bool canAdd = true;
						for (int done : edgeDones)
						{
							if (done == (*j)->getEnd())
							{
								canAdd = false;
							}
						}
						if (canAdd)
						{
							valToAdd = curr_edge;
							edgeD = (*j)->getEnd();
							lowest_val = (*j)->getWeight();
						}					

					}

					++j;

				}
			}
		}



		edgeFolowing.push_back(valToAdd);
		edgeDones.push_back(edgeD);
	} while (edgeDones.size() != _graph->getVerticeAmount());

	if (print)
	{
		std::cout << "Wynik:" << std::endl;

		for (int i = 0; i<edgeFolowing.size(); i++)
		{
			std::cout << edgeDones[i + 1] << "-";
			std::cout << edgeFolowing[i] << std::endl;
		}

		std::cout << std::endl;
		std::cout << std::endl;
	}

}

Prim::Prim()
{
}


Prim::~Prim()
{
}
