#include "stdafx.h"
#include "Dijkstra.h"
#include <functional>
#include <algorithm>
#include <iostream>

void Dijkstra::Dijkstra_Matrix(Graph * _graph, int vStart)
{
	std::vector<int> S;
	std::vector<int> Q;
	std::vector<int> QtoS;

	int * d = new int[_graph->getVerticeAmount()];
	int * p = new int[_graph->getVerticeAmount()];

	for (int i=0;i<_graph->getVerticeAmount();i++)
	{
		Q.push_back(i);
		d[i] = INT32_MAX;
		p[i] = -1;
	}

	d[vStart] = 0;
	QtoS.push_back(vStart);


	do
	{
		for (int qTOs : QtoS)
		{
			Q.erase(std::remove(Q.begin(), Q.end(), qTOs), Q.end());
			S.push_back(qTOs);
		}

		QtoS.clear();

		for (int s : S)
		{
			for (int j = 0; j<_graph->getEdgeAmount(); j++)
			{
				if (_graph->getGraphMatrix()[s][j]>0)
				{
					for (int i = 0; i < _graph->getVerticeAmount(); i++) {

						if (_graph->getGraphMatrix()[i][j]<0) //krawedz o wadze sj do wierzcholka i
						{
							if (d[i]>d[s] + _graph->getGraphMatrix()[s][j])
							{
								d[i] = d[s] + _graph->getGraphMatrix()[s][j];
								p[i] = s;
								QtoS.push_back(i);
							}

						}
					}
				}

			}
		}



	}
	while (Q.size() != 0);


	for (int i = 0; i<_graph->getVerticeAmount(); i++)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (int i=0;i<_graph->getVerticeAmount();i++)
	{
		std::cout << d[i]<<" ";
	}
	std::cout << std::endl;
	for (int i = 0; i<_graph->getVerticeAmount(); i++)
	{
		std::cout << p[i] << " ";
	}
	std::cout << std::endl;
}

void Dijkstra::Dijkstra_List(Graph * _graph, int vStart)
{

}

Dijkstra::Dijkstra()
{
}


Dijkstra::~Dijkstra()
{
}
