#include "Mesh.h"

Mesh::Mesh(std::string fullPath)
{
	this->path = fullPath;
	//const char* temp = fullPath.c_str();
	this->model = Graphics::device->getSceneManager()->getMesh(fullPath.c_str());
	this->mesh = Graphics::device->getSceneManager()->addAnimatedMeshSceneNode(this->model);
	this->mesh->setMaterialFlag(video::EMF_LIGHTING, false);
}

Mesh::~Mesh()
{
	delete this;
}
