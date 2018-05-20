#pragma once
#include <string>

class GGenerator
{
public:
	static  void generateGraph(int verticeAmount, float density, bool isDirected, int valueRange, int startValue, std::string fileName);
	
private:
	GGenerator();
	~GGenerator();
};

