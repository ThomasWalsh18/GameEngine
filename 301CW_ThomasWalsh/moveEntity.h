#pragma once
#include "Entity.h"
#include "AssetManager.h"

class moveEntity : public Entity
{
public:
	moveEntity(glm::vec3 pos, float mass, std::string modelName, std::string filename, EntityEnum type, std::string texture);
	~moveEntity();

	std::string Asset;
	Mesh* currentMesh = nullptr;
	btRigidBody* body;
	std::string texture;
	scene::IAnimatedMeshSceneNode* animatedSceneNode;
	float mass;
	Mesh* getCurrentMesh();

	scene::IAnimatedMeshSceneNode* GetSceneNode();
	void SetSceneNode(scene::IAnimatedMesh* model);

	btRigidBody* getRigidBody();
	void setRigidBody(btRigidBody* body);

	std::string getTexture();
	void setTexture(std::string tex);

	float getMass();
	void setMass(float mass);

	void destroy();
};

