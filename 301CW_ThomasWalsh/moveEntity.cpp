#include "moveEntity.h"

moveEntity::moveEntity(glm::vec3 pos, std::string modelName) : Entity(pos, type)
{
	this->Asset = modelName;
	this->currentMesh = AssetManager::GetModel(modelName);
}

moveEntity::~moveEntity()
{

}

Mesh* moveEntity::getCurrentMesh()
{
	return this->currentMesh;
}
