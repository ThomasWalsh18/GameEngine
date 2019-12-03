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

	virtual btRigidBody* getRigidBody();
	virtual void setRigidBody(btRigidBody* body);

	/*

	___________________________________________________________________________________________________________________________________

	WhenEvers:
	Then audio -> looks easy so I think I can do whenever I have a few hours spare, got loads of royalty free music
	Then game logic
	And A math liabry
	___________________________________________________________________________________________________________________________________

	Questions:
	A clean up question
		Virtual function for events->eventinfo?
	___________________________________________________________________________________________________________________________________

	General To do:
	General Clean up of code
		Clean up UI class so that It looks proper and can suport different input devices
		Make the Asset Manager load textures so that I can fix the sky box
	__________________________________________________________________________________________________________________________________

	Physics -> movement in properly(forces, and also relevant to the heading) also collisions, and bullets
	___________________________________________________________________________________________________________________________________

	Then add lua ( look on the example lua files and then the slides from week nine to see what I can lua file)
	___________________________________________________________________________________________________________________________________

	Networking -> looks difficult would like to spend an entire week on it / more if I can.
			   -> dead reckioning tiume steps and position and veleocity prediction of position for smoother model movement as well as cheat detection
*/
};



