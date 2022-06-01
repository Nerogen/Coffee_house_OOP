#pragma once
#include "RecipeStep.h"
#include "Visitor.h"
#include <deque>
#include <map>
#include "Recipe.h"
#include <string>
#include "Settings.h"

class Worker
{
public:
	Worker();
	std::string process(Visitor& visitor, std::map<std::string, int>& dessertMap, std::map<std::string, Recipe>& recipeMap, std::map<std::string, int>& ingredientMap, long& time);
	virtual int makeStep(std::map<std::string, int>& ingredientMap, std::deque<RecipeStep>& steps, long& time);
	bool takeIngredients(std::map<std::string, int>& ingredientMap, std::string name, int number_of);
	bool takeDessert(std::map<std::string, int>& dessertMap, std::string name, int number_of);
};