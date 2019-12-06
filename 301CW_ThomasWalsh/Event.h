#pragma once
#include <vector>
#include <string>
#include "EventTypeEnum.h"
#include "SubSystemEnum.h"
#include "Entity.h"


class Event 
{
	/*
	This is really unneeded at the moment, however in the future the einfo could be made virtual
	As well as this different event classes could have been made, then each event would have a Einfo 
	That holds relevant information about its own event
	*/
	struct einfo {
		int dir = 0;
		float speed = 0;
		std::vector<Entity*> affEntities;
		int x;
		int y;

		float radi;
		float posx;
		float posy;
		float posz;
		float mass;
		float height;
		float width;
		float depth;

		int level;

		glm::vec3 Header;
	};

public:

	Event(EventTypeEnum typeOfEvent);
	~Event();
	einfo eventInfo;
	EventTypeEnum functPoint;
	std::vector<SubSystemEnum> mySubs;

};

