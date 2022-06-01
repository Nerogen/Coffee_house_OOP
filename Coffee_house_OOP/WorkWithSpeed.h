#pragma once
#include "Worker.h"

class WorkWithSpeed: public Worker
{
public:
	virtual int makeStep(std::map<std::string, int>& ingredientMap, std::deque<RecipeStep>& steps, long& time);
private:
	int speed = rand() % 3 + 10;
};

