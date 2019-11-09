#pragma once
#include "Entity.h"
class CameraEntitiy : public Entity
{
public:
	CameraEntitiy(glm::vec3 pos, EntityEnum type);
	~CameraEntitiy();
	glm::vec3 targetPos;
	int FOV = 60;
	glm::vec3 getTargetPos();
	void setTargetPos(glm::vec3 targetPos);
};

