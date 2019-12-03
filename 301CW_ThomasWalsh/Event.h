#pragma once
#include <vector>
#include <string>
#include "EventTypeEnum.h"
#include "SubSystemEnum.h"
#include "Entity.h"


class Event 
{
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

		glm::vec3 Header;
	};

public:

	Event(EventTypeEnum typeOfEvent);
	~Event();
	einfo eventInfo;
	EventTypeEnum functPoint;
	void addSubSystem(SubSystemEnum sub);
	std::vector<SubSystemEnum> mySubs;

};

