#pragma once
#include "Entity.h"
#include "AssetManager.h"

class moveEntity : public Entity
{
public:
	moveEntity(glm::vec3 pos, std::string modelName);
	~moveEntity();
	std::string Asset;
	Mesh* currentMesh;
	Mesh* getCurrentMesh();

	

};

