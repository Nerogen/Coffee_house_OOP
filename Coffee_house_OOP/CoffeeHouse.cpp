#include "CoffeeHouse.h"

CoffeeHouse::CoffeeHouse()
{
}

void CoffeeHouse::run()
{
    while (currentTime < Settings::CLOSING_TIME) {
        std::cout << "Current rating sum: " << ratingSum << std::endl;
        std::cout << "Current rating amount: " << ratingAmount << std::endl;
        if (Settings::VISITOR_GENERATE_TIME_PERIOD % currentTime == 0) {
           queue.addVisitor(3, menuList);
        }

        for (int i = 0; i < numberOfDesks; ++i) {
            if (queue.getQueue().size()) {
                desk.addVisitorToQueue(queue.getQueue()[0]);
                queue.deQueueVisitor(0);
                if ((queue.getQueue()[0].getChoice() == "Late") || (queue.getQueue()[0].getChoice() == "Raf") || (queue.getQueue()[0].getChoice() == "Cappuccino")) {
                    amountOfdrink += 1;
                }
                int rating = desk.executeAnOrder(dessertMap, recipeMap, ingredientMap, currentTime);
                if (rating) {
                    ratingSum += rating;
                    ratingAmount += 1;
                }
            }
        }

        if (Settings::VISITOR_WAITING_TIME % currentTime == 0) {
            queue.deQueueVisitor(3);
        }

        currentTime += Settings::TICK_TIME;
    }
}

float CoffeeHouse::getAvgRating()
{
    return (float)ratingSum / (float)ratingAmount;
}

void CoffeeHouse::addDessert(Product dessert, int amount)
{
    dessertMap[dessert.getName()] = amount;
    menuList.push_back(dessert.getName());
}

void CoffeeHouse::addRecipe(Product& product, Recipe& recipe)
{
    recipeMap[product.getName()] = recipe;
    menuList.push_back(product.getName());
}

void CoffeeHouse::addIngredient(Ingredient& ingredient, int amount)
{
    ingredientMap[ingredient.getName()] = amount;
}

std::deque<std::string> CoffeeHouse::getMenu()
{
    return menuList;
}

std::map<std::string, int> CoffeeHouse::getDeserts()
{
    return dessertMap;
}

std::map<std::string, Recipe> CoffeeHouse::getRecipeMap()
{
    return recipeMap;
}

std::map<std::string, int> CoffeeHouse::getIngredients()
{
    return ingredientMap;
}

long CoffeeHouse::getCurrentTime()
{
    return currentTime;
}

void CoffeeHouse::updateTime(long time)
{
    this->currentTime += time;
}

long CoffeeHouse::getRatingSum()
{
    return ratingSum;
}

long CoffeeHouse::getRatingAmount()
{
    return ratingAmount;
}

long CoffeeHouse::getAmountOfDrink()
{
    return amountOfdrink;
}

void CoffeeHouse::setNumberOfDesks(int numberOf)
{
    this->numberOfDesks = numberOf;
}
