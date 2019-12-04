#pragma once
#include "Entity.h"
class BoxEntity : public Entity
{
public:
	BoxEntity(glm::vec3 pos, float mass, float size, glm::vec3 rotate, glm::vec3 scale, EntityEnum type, std::string texture);
	~BoxEntity();
	scene::IMeshSceneNode* box;

	std::string texture;
	glm::vec3 scale;
	glm::vec3 rotation;
	btRigidBody* body;
	float size;
	float mass;

	scene::IMeshSceneNode* GetSimpleSceneNode();
	void SetSimpleSceneNode(scene::IMeshSceneNode* model);

	std::string getTexture();
	void setTexture(std::string tex);

	glm::vec3 getRotation();
	void setRotation(glm::vec3 rot);

	glm::vec3 getScale();
	void setScale(glm::vec3 scale);

	float getSize();
	void setSize(float size);

	btRigidBody* getRigidBody();
	void setRigidBody(btRigidBody* body);
	
	float getMass();
	void setMass(float mass);
};

