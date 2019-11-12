#pragma once
#include "EntityEnum.h"
#include "Mesh.h"
#include <glm.hpp>
#include <iostream>


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

};

/*

	Models in whenever avaialble

	Questions: 
	Mouse move screen height and width
	__________________________________________________________________________________________________________________________________

	Physics -> movement in properly(forces, and also relevant to the heading) also collisions, and bullets
	___________________________________________________________________________________________________________________________________

	Then add lua ( look on the example lua files and then the slides from week nine to see what I can lua file)
	___________________________________________________________________________________________________________________________________

	Then audio 
	___________________________________________________________________________________________________________________________________

	Then game logic
	And A math liabry
	___________________________________________________________________________________________________________________________________

	Networking :/
*/

