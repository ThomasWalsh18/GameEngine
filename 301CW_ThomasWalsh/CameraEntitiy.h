#pragma once
#include "Entity.h"
class CameraEntitiy : public Entity
{
public:
	CameraEntitiy();
	~CameraEntitiy();
	glm::vec3 targetPos;
	int FOV = 60;

};

