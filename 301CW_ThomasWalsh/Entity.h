#pragma once
#include "EntityEnum.h"
#include "Mesh.h"
#include <glm.hpp>
#include <iostream>
#include "btBulletDynamicsCommon.h"

class Entity 
{
public:
	Entity(glm::vec3 pos, EntityEnum type);
	~Entity();
	glm::vec3 position;
	EntityEnum type;

	virtual Mesh* getCurrentMesh();

	virtual glm::vec3 getTargetPos();
	virtual void setTargetPos(glm::vec3 targetPos);

	virtual scene::IAnimatedMeshSceneNode* GetSceneNode();
	virtual void SetSceneNode(scene::IAnimatedMesh* model);
	
	virtual scene::IMeshSceneNode* GetSimpleSceneNode();
	virtual void SetSimpleSceneNode(scene::IMeshSceneNode* model);

	virtual btRigidBody* getRigidBody();
	virtual void setRigidBody(btRigidBody* body);
	
	virtual std::string getTexture();
	virtual void setTexture(std::string tex);

	virtual glm::vec3 getRotation();
	virtual void setRotation(glm::vec3 rot);
	
	virtual glm::vec3 getScale();
	virtual void setScale(glm::vec3 scale);

	virtual float getSize();
	virtual void setSize(float size);

	virtual glm::vec3 getPosition();
	virtual void setPosition(glm::vec3 newPos);

	virtual float getMass();
	virtual void setMass(float mass);

	/*

	___________________________________________________________________________________________________________________________________

	WhenEvers:
	Game logic - Need a win con
	And A math liabry
	___________________________________________________________________________________________________________________________________

	General To do:
		General Clean up of code
		Clean up UI class so that It looks proper and can suport different input devices
		Make the Asset Manager load textures so that I can fix the sky box
		Comment Everything
	__________________________________________________________________________________________________________________________________

	Physics -> movement in properly(forces, and also relevant to the heading) also collisions, and bullets
	___________________________________________________________________________________________________________________________________

	Networking -> looks difficult would like to spend an entire week on it / more if I can.
			   -> dead reckioning tiume steps and position and veleocity prediction of position for smoother model movement as well as cheat detection
*/
};



