#include "moveEntity.h"

moveEntity::moveEntity(glm::vec3 pos, std::string modelName, EntityEnum type) : Entity(pos, type)
{
	this->Asset = modelName;
	this->currentMesh = AssetManager::GetModel(modelName);
	btTransform t;
	t.setIdentity();
	t.setOrigin(btVector3(0, 0, 0));
	btStaticPlaneShape* plane = new btStaticPlaneShape(btVector3(0, 1, 0), btScalar(0));
	btMotionState* motion = new btDefaultMotionState(t); // shape 
	btRigidBody::btRigidBodyConstructionInfo info(btScalar(0), motion, plane);
	btRigidBody* body = new btRigidBody(info);
	this->body = body;
}

moveEntity::~moveEntity()
{

}

Mesh* moveEntity::getCurrentMesh()
{
	return this->currentMesh;
}

scene::IAnimatedMeshSceneNode* moveEntity::GetSceneNode()
{
	return this->animatedSceneNode;
}

void moveEntity::SetSceneNode(scene::IAnimatedMesh* model)
{
	this->animatedSceneNode = IrrInclude::device->getSceneManager()->addAnimatedMeshSceneNode(model);
}

btRigidBody* moveEntity::getRigidBody()
{
	return this->body;
}

void moveEntity::setRigidBody(btRigidBody* body)
{
	this->body = body;
}
