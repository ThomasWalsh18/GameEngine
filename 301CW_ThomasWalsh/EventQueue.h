#pragma once
#include <vector>
#include "Event.h"
class EventQueue
{
public:

	EventQueue();
	~EventQueue();
	void addEvent(Event* action);
	//bool exitLoop = false;
};

