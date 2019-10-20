#pragma once
#include <vector>
#include "Event.h"
class EventQueue
{
public:
	static std::vector<Event*> eventQueue;
	EventQueue();
	~EventQueue();
	void addEvent(Event* action);
	bool exitLoop = false;
};

