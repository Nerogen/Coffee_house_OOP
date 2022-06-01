#pragma once
#include <deque>
#include <map>
#include <string>
#include "Recipe.h"
#include "Worker.h"
#include "Visitor.h"
#include "WorkWithSpeed.h"

class CashDesk
{
public:
    CashDesk();
    void addVisitorToQueue(Visitor& visitor);
    int executeAnOrder(std::map<std::string, int>& dessertMap, std::map<std::string, Recipe>& recipeMap, std::map<std::string, int>& ingredientMap, long& currentTime);
    void removeVisitor(Visitor& visitor);
    std::deque<Visitor> getVisitorList();

private:
    WorkWithSpeed worker;
    std::deque<Visitor> visitorQueue;
};

