#include "VisitorGenerator.h"

VisitorGenerator::VisitorGenerator()
{
}

void VisitorGenerator::addVisitor(int number_of_new_visitors, std::deque<std::string>& menu)
{
	for (int i = 0; i < number_of_new_visitors; ++i) {
		Visitor visitor(menu);
		this->queue.push_back(visitor);
	}
}

void VisitorGenerator::deQueueVisitor(int number_of_visitors)
{
	for (int i = 0; i < number_of_visitors; ++i) {
		this->queue.pop_front();
	}
}

std::deque<Visitor> VisitorGenerator::getQueue()
{
	return this->queue;
}
