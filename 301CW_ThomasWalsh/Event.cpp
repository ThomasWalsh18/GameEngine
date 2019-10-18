#include "Event.h"

Event::Event(EventTypeEnum event)
{
}

Event::~Event()
{
}

void Event::addSubSystem(SubSystemEnum sub)
{
	mySubs.push_back(sub);
}
