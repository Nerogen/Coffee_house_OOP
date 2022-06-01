#include "CashDesk.h"

CashDesk::CashDesk()
{
}

void CashDesk::addVisitorToQueue(Visitor& visitor)
{
	visitorQueue.push_back(visitor);
}

int CashDesk::executeAnOrder(std::map<std::string, int>& dessertMap, std::map<std::string, Recipe>& recipeMap, std::map<std::string, int>& ingredientMap, long& currentTime)
{
	std::string order = worker.process(visitorQueue[0], dessertMap, recipeMap, ingredientMap, currentTime);
	int mark = visitorQueue[0].getRating(order);
	removeVisitor(visitorQueue[0]);
	return mark;
}

void CashDesk::removeVisitor(Visitor& visitor)
{
	visitorQueue.pop_front();
}

std::deque<Visitor> CashDesk::getVisitorList()
{
	return visitorQueue;
}

