#pragma once
#include "Entity.h"
class RectEntity : public Entity
{
public:
	RectEntity(glm::vec3 pos, float width, float height);
	~RectEntity();
	float width = 0.0f;
	float height = 0.0f;
};

