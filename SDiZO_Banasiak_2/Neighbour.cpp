#include "stdafx.h"
#include "Neighbour.h"
#include <iostream>
#include <string>


int Neighbour::getWeight()
const
{
	return weight;
}

int Neighbour::getEnd()
const
{
	return end;
}

Neighbour::Neighbour(int weight, int end)
{
	this->weight = weight;
	this->end = end;
}

Neighbour::Neighbour()
{
}


Neighbour::~Neighbour()
{
}



void Neighbour::print()
{
	std::cout << "S: [" << getEnd() << "] W: [" << getWeight() << "]" << " || ";
}

