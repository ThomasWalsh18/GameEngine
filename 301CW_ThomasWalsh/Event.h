#pragma once
#include <vector>
#include <string>
#include "EventTypeEnum.h"
#include "SubSystemEnum.h"
#include "Entity.h"


class Event 
{
	virtual struct einfo {
		int dir = 0;
		float speed = 0;
		std::vector<Entity*> affEntities;
	};

public:

	Event(EventTypeEnum typeOEvent);
	~Event();
	einfo eventInfo;
	EventTypeEnum functPoint;
	void addSubSystem(SubSystemEnum sub);
	std::vector<SubSystemEnum> mySubs;

};

