#pragma once
#include "EntityEnum.h"
#include <glm.hpp>


class Entity 
{
public:
	Entity(glm::vec3 pos, EntityEnum type);
	~Entity();
	glm::vec3 position;
	EntityEnum type;
};

