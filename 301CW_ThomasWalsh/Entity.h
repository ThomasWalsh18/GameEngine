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
	__________________________________________________________________________________________________________________________________

	Then add lua
	___________________________________________________________________________________________________________________________________

	Then try the mouse movement  http://www.cplusplus.com/forum/beginner/11226/
	___________________________________________________________________________________________________________________________________

	Then audio 
	___________________________________________________________________________________________________________________________________

	Physics
	___________________________________________________________________________________________________________________________________

	Then game logic
	And A math liabry
	___________________________________________________________________________________________________________________________________

	Networking :/
*/

