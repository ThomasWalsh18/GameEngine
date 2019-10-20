#include "EventQueue.h"

EventQueue::EventQueue()
{
}

EventQueue::~EventQueue()
{
}

void EventQueue::addEvent(Event* action)
{
	this->eventQueue.push_back(action);
}

