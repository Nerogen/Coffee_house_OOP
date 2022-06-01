#pragma once
#include <map>
#include <deque>
#include <iostream>
#include "Ingredient.h"
#include "CashDesk.h"
#include "KitchenMachine.h"
#include "Product.h"
#include "Recipe.h"
#include "RecipeStep.h"
#include "Settings.h"
#include "Visitor.h"
#include "VisitorGenerator.h"

class CoffeeHouse
{
public:
    CoffeeHouse();
    void run();
    void addDessert(Product& dessert, int amount);
    void addRecipe(Product& product, Recipe& recipe);
    void addIngredient(Ingredient& ingredient, int amount);
    float getAvgRating();
    std::deque<std::string> getMenu();
    std::map<std::string, int> getDeserts();
    std::map<std::string, Recipe> getRecipeMap();
    std::map<std::string, int> getIngredients();
    long getCurrentTime();
    void updateTime(long time);
    long getRatingSum();
    long getRatingAmount();
    long getAmountOfDrink();
    void setNumberOfDesks(int numberOf);

private:
    std::map<std::string, int> dessertMap;
    std::map<std::string, Recipe> recipeMap;
    std::map<std::string, int> ingredientMap;
    std::deque<std::string> menuList;
    VisitorGenerator queue;
    CashDesk desk;

    long currentTime = 1;
    long ratingSum = 0;
    long ratingAmount = 0;
    long amountOfdrink = 0;
    int numberOfDesks = 0;
};
