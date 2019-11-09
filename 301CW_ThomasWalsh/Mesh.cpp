#include "Mesh.h"

Mesh::Mesh(std::string fullPath)
{
	this->path = fullPath;
	this->model = IrrInclude::device->getSceneManager()->getMesh(fullPath.c_str());
	//this->mesh = IrrInclude::device->getSceneManager()->addAnimatedMeshSceneNode(this->model);
	//this->mesh->setMaterialFlag(video::EMF_LIGHTING, false);
	// next task is making the cannon an entity
	// then seeing if i can make 2 in different positions with my entity system
	// also see if I have to load all the objects into the scene at once
}

Mesh::~Mesh()
{
	//delete this;
}
