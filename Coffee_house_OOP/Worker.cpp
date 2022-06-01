#include "Worker.h"

Worker::Worker()
{
}

std::string Worker::process(Visitor& visitor, std::map<std::string, int>& dessertMap, std::map<std::string, Recipe>& recipeMap, std::map<std::string, int>& ingredientMap, long& time)
{
    bool flag = takeDessert(dessertMap, visitor.getChoice(), 1);
    if (flag) {
          time += Settings::TICK_TIME;
          return visitor.getChoice();
    }

   auto ite = recipeMap.begin();
   for (; ite != recipeMap.end(); ite++)
        if (((*ite).first == visitor.getChoice())) {
            auto steps = ite->second.getStepList();
           if (makeStep(ingredientMap, steps, time) == 1) {
               time += Settings::TICK_TIME;
              return visitor.getChoice();
           }
            else {
                return "None";
            }
        }
    return "None";
}

int Worker::makeStep(std::map<std::string, int>& ingredientMap, std::deque<RecipeStep>& steps, long& time)
{
       for (int i = 0; i < steps.size(); ++i) {
            if (takeIngredients(ingredientMap, steps[i].getIngredient(), steps[i].getAmount())) {
                time += steps[i].getTime();
                return 1;
            }
            else {
                return 0;
            }
       }
    return 1;
}

bool Worker::takeIngredients(std::map<std::string, int>& ingredientMap, std::string name, int number_of)
{
    auto it = ingredientMap.begin();
    for (; it != ingredientMap.end(); it++)
        if (((*it).first == name) && it->second >= number_of) {
            it->second -= number_of;
            return true;
        }
    return false;
}

bool Worker::takeDessert(std::map<std::string, int>& dessertMap, std::string name, int number_of)
{
    if (dessertMap[name] >= number_of) {
        dessertMap[name] -= number_of;
        return true;
    }
    return false;
}
