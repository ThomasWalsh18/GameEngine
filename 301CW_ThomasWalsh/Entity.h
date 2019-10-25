#pragma once
#include "subSystem.h"
#include <glm.hpp>
class Entity : public subSystem
{
public:
	Entity(glm::vec3 pos);
	~Entity();
	glm::vec3 position;
};

