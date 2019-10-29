#include "Event.h"

Event::Event(EventTypeEnum typeOEvent)
{
	if (typeOEvent == EventTypeEnum(0)) { // if move event
		this->mySubs.push_back(SubSystemEnum(1)); // we need these subsystems for a move event
		this->mySubs.push_back(SubSystemEnum(2));
		this->mySubs.push_back(SubSystemEnum(3));
	}
	functPoint = typeOEvent;
	
}

Event::~Event()
{
}

void Event::addSubSystem(SubSystemEnum sub)
{
	mySubs.push_back(sub);
}
