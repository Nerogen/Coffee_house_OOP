#include "Visitor.h"

Visitor::Visitor(std::deque<std::string> menu)
{
    std::deque<std::string> menus(menu);
    int num = getChoice(menus.size());
    while (num >= menus.size()) {
        num -= 1;
    }
	this->choice = menus[num];
}

int Visitor::getChoice(int number_of_products)
{
	return rand() % 3 + number_of_products;
}

int Visitor::getRating(std::string product)
{
    if (product == choice) {
        return 5;
    }
    else {
        return 1;
    }
}

std::string Visitor::getChoice()
{
    return choice;
}
