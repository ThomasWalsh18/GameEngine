#include "CameraEntitiy.h"

CameraEntitiy::CameraEntitiy(glm::vec3 pos, EntityEnum type) : Entity(pos, type)
{
	
}

CameraEntitiy::~CameraEntitiy()
{
}

glm::vec3 CameraEntitiy::getTargetPos()
{
	return this->targetPos;
}

void CameraEntitiy::setTargetPos(glm::vec3 targetPos)
{
	this->targetPos = targetPos;
}
