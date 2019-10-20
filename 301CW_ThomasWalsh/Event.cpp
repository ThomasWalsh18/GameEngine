#include "Event.h"

Event::Event(EventTypeEnum typeOEvent)
{
	if (typeOEvent == EventTypeEnum(0)) { // if move event
		addSubSystem(SubSystemEnum(1)); // we need these subsystems for a move event
		addSubSystem(SubSystemEnum(2));
	}
	
}

Event::~Event()
{
}

void Event::addSubSystem(SubSystemEnum sub)
{
	mySubs.push_back(sub);
}
