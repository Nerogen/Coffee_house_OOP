#include "WorkWithSpeed.h"

int WorkWithSpeed::makeStep(std::map<std::string, int>& ingredientMap, std::deque<RecipeStep>& steps, long& time)
{
        for (int i = 0; i < steps.size(); ++i) {
            if (takeIngredients(ingredientMap, steps[i].getIngredient(), steps[i].getAmount())) {
                time += steps[i].getTime() / speed;
                return 1;
            }
            else {
                return 0;
            }
        }
        return 1;
}
