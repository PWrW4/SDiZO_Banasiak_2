#pragma once
#include <ostream>
#include <string>

class Neighbour
{
private:
	int weight;
	int end;
public:
	int getWeight()const;
	int getEnd()const;
	Neighbour(int weight, int end);
	Neighbour();
	~Neighbour();
	void print();
};

