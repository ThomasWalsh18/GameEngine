#pragma once
#include "Entity.h"
#include "AssetManager.h"

class moveEntity : public Entity
{
public:
	moveEntity(glm::vec3 pos, std::string modelName, EntityEnum type);
	~moveEntity();
	std::string Asset;
	Mesh* currentMesh;
	Mesh* getCurrentMesh();
	scene::IAnimatedMeshSceneNode* GetSceneNode();
	void SetSceneNode(scene::IAnimatedMesh* model);
	scene::IAnimatedMeshSceneNode* animatedSceneNode;
};

