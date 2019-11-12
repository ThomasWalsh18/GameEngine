#include "Entity.h"

Entity::Entity(glm::vec3 pos, EntityEnum type)
{
	this->position = pos;
	this->type = type;
}

Entity::~Entity()
{
	//delete this;
}

Mesh* Entity::getCurrentMesh()
{
	return nullptr;
}

glm::vec3 Entity::getTargetPos()
{
	return glm::vec3(0.0f);
}

void Entity::setTargetPos(glm::vec3 targetPos)
{
}

scene::IAnimatedMeshSceneNode* Entity::GetSceneNode()
{
	return nullptr;
}

void Entity::SetSceneNode(scene::IAnimatedMesh* model)
{
}
