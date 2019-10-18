#pragma once
#include <vector>
#include "Event.h"
class EventQueue
{
public:
	//singleton
	static EventQueue& getInstance() {
		static EventQueue instance;
		return instance;
	}
	static std::vector<Event> eventQueue;
	void addEvent();

private:
	EventQueue() {}
	EventQueue(EventQueue const&) = delete;
	void operator=(EventQueue const&) = delete;
};

