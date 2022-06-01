#include "Application.h"

Application::Application() {
    CoffeeHouse model = Application::build();
    std::cout << "Start modeling" << std::endl;
    std::map<std::string, int> desertsBefore(model.getDeserts());
    model.run();
    std::cout << "Today rating is: " << model.getAvgRating() << std::endl;
    // last extend (all statistics) 
    int soldDeserts = 0;
    auto ite = desertsBefore.begin();
    for (; ite != desertsBefore.end(); ite++){
        soldDeserts += ite->second - model.getDeserts()[(*ite).first];
    }
    std::cout << "Sales statistics for today: " << std::endl;
    std::cout << "Number of visitors: " << model.getRatingAmount() << std::endl;
    std::cout << "number of sold desserts: " << soldDeserts << std::endl;
    std::cout << "number of sold drinks: " << model.getAmountOfDrink() << std::endl;
}

CoffeeHouse Application::build()
{
    CoffeeHouse model;

    Product cookie("Cookie", false);
    Product pastry("Pastry", false);
    Product cake("cake", false);
    model.addDessert(cookie, 20);
    model.addDessert(pastry, 20);
    model.addDessert(cake, 20);

    Ingredient coffeeBeans("Coffee beans");
    Ingredient milk("Milk");
    Ingredient syrup("Syrup");

    model.addIngredient(coffeeBeans, 1000);
    model.addIngredient(milk, 200);
    model.addIngredient(syrup, 100);

    KitchenMachine coffeeMachine("Coffee machine");
    KitchenMachine cappuccinatore("Cappuccinatore");

    Product late("Late", true);
    Recipe recipeOFLate;
    RecipeStep recipeStepOfLate(coffeeBeans, 5, coffeeMachine, 120);
    recipeOFLate.addStep(recipeStepOfLate);

    model.addRecipe(
        late,
        recipeOFLate
    );
    KitchenMachine none;

    Product raf("Raf", true);
    Recipe recipeOfRaf; 
    RecipeStep firstResipeStepOfRaf(syrup, 10, none, 10);
    RecipeStep secondResipeStepOfRaf(coffeeBeans, 5, coffeeMachine, 120);
    RecipeStep thirdResipeStepOfRaf(milk, 10, cappuccinatore, 100);

    recipeOfRaf.addStep(firstResipeStepOfRaf);
    recipeOfRaf.addStep(secondResipeStepOfRaf);
    recipeOfRaf.addStep(thirdResipeStepOfRaf);

    model.addRecipe(
        raf,
        recipeOfRaf
    );

    Product cappuccino("Cappuccino", true);
    Recipe recipeOfCappuccino;
    RecipeStep firstRecipeOfCappuccino(coffeeBeans, 5, coffeeMachine, 120);
    RecipeStep secondRecipeOfCappuccino(milk, 10, none, 10);
    RecipeStep thirdRecipeOfCappuccino(milk, 10, cappuccinatore, 100);


    recipeOfCappuccino.addStep(firstRecipeOfCappuccino);
    recipeOfCappuccino.addStep(secondRecipeOfCappuccino);
    recipeOfCappuccino.addStep(thirdRecipeOfCappuccino);


    model.addRecipe(
        cappuccino,
        recipeOfCappuccino
    );

    model.setNumberOfDesks(2);

    return model;
}