#include "BoxEntity.h"

BoxEntity::BoxEntity(glm::vec3 pos, float mass, float size, glm::vec3 rotate, glm::vec3 scale, EntityEnum type, std::string texture) : Entity(pos, type)
{
	//needed a blank physics body
	btTransform t;
	t.setIdentity();
	t.setOrigin(btVector3(0, 0, 0));
	btStaticPlaneShape* plane = new btStaticPlaneShape(btVector3(0, 1, 0), btScalar(0));
	btMotionState* motion = new btDefaultMotionState(t); // shape 
	btRigidBody::btRigidBodyConstructionInfo info(btScalar(0), motion, plane);
	btRigidBody* body = new btRigidBody(info);
	this->body = body;
	this->texture = texture;
	this->rotation = rotate;
	this->scale = scale;
	this->size = size;
	this->mass = mass;
}

BoxEntity::~BoxEntity()
{
	delete this;
}

scene::IMeshSceneNode* BoxEntity::GetSimpleSceneNode()
{
	return this->box;
}

void BoxEntity::SetSimpleSceneNode(scene::IMeshSceneNode* model)
{
	this->box = model;
}

std::string BoxEntity::getTexture()
{
	return this->texture;
}

void BoxEntity::setTexture(std::string tex)
{
	this->texture = tex;
}

glm::vec3 BoxEntity::getRotation()
{
	return this->rotation;
}

void BoxEntity::setRotation(glm::vec3 rot)
{
	this->rotation = rot;
}

glm::vec3 BoxEntity::getScale()
{
	return this->scale;
}

void BoxEntity::setScale(glm::vec3 scale)
{
	this->scale = scale;
}

float BoxEntity::getSize()
{
	return this->size;
}

void BoxEntity::setSize(float size)
{
	this->size = size;
}

btRigidBody* BoxEntity::getRigidBody()
{
	return this->body;
}

void BoxEntity::setRigidBody(btRigidBody* body)
{
	this->body = body;
}

float BoxEntity::getMass()
{
	return this->mass;
}

void BoxEntity::setMass(float mass)
{
	this->mass = mass;
}
