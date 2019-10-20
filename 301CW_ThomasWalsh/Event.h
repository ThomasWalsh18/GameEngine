#pragma once
#include <vector>
#include <string>
#include "EventTypeEnum.h"
#include "SubSystemEnum.h"

class Event 
{
public:
	Event(EventTypeEnum typeOEvent);
	~Event();
	void addSubSystem(SubSystemEnum sub);
	std::vector<SubSystemEnum> mySubs;
};

