#include "Mesh.h"

Mesh::Mesh(std::string fullPath)
{
	this->path = fullPath;
	this->model = IrrInclude::device->getSceneManager()->getMesh(fullPath.c_str());
	this->mesh = IrrInclude::device->getSceneManager()->addAnimatedMeshSceneNode(this->model);
	this->mesh->setMaterialFlag(video::EMF_LIGHTING, false);
}

Mesh::~Mesh()
{
	delete this;
}
