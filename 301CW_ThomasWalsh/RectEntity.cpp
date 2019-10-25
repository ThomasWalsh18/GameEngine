#include "RectEntity.h"

RectEntity::RectEntity(glm::vec3 pos, float width, float height) : Entity(pos)
{
	this->width = width;
	this->height = height;
}

RectEntity::~RectEntity()
{

}
