#pragma once
#include "Visitor.h"
#include <list>
#include <iostream>

class VisitorGenerator
{
public:
	VisitorGenerator();
	void addVisitor(int number_of_new_visitors, std::deque<std::string>& menu);
	void deQueueVisitor(int number_of_visitors);
	std::deque<Visitor> getQueue();

private:
	std::deque<Visitor> queue;
};