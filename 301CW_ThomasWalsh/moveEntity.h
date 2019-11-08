#pragma once
#include "Entity.h"
#include "Mesh.h"
class moveEntity : public Entity
{
public:
	moveEntity(glm::vec3 pos, ModelType typeOfModel);
	~moveEntity();
	ModelType Asset;
	//Mesh* mesh;

};

