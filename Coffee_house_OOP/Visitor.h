#pragma once
#include <string>
#include <deque>

class Visitor
{
public:
    Visitor(std::deque<std::string> menu);
    int getChoice(int number_of_products);
    int getRating(std::string product);
    std::string getChoice();

private:
    std::string choice;
};
