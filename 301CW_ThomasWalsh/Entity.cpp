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

scene::IMeshSceneNode* Entity::GetSimpleSceneNode()
{
	return nullptr;
}

void Entity::SetSimpleSceneNode(scene::IMeshSceneNode* model)
{
}

btRigidBody* Entity::getRigidBody()
{
	return nullptr;
}

void Entity::setRigidBody(btRigidBody* body)
{
	
}

std::string Entity::getTexture()
{
	return std::string("");
}

void Entity::setTexture(std::string tex)
{

}

glm::vec3 Entity::getRotation()
{
	return glm::vec3();
}

void Entity::setRotation(glm::vec3 rot)
{
}

glm::vec3 Entity::getScale()
{
	return glm::vec3();
}

void Entity::setScale(glm::vec3 scale)
{
}

float Entity::getSize()
{
	return 0.0f;
}

void Entity::setSize(float size)
{
}

glm::vec3 Entity::getPosition()
{
	return this->position;
}

void Entity::setPosition(glm::vec3 newPos)
{
	this->position = newPos;
}

float Entity::getMass()
{
	return 0.0f;
}

void Entity::setMass(float mass)
{
}
