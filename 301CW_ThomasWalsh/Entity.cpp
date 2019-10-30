#include "Entity.h"

Entity::Entity(glm::vec3 pos, EntityEnum type)
{
	this->position = pos;
	this->type = type;
}

Entity::~Entity()
{
	delete this;
}
