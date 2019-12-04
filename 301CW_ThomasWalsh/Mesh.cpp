#include "Mesh.h"

Mesh::Mesh(std::string fullPath)
{
	this->path = fullPath;
	this->model = IrrInclude::device->getSceneManager()->getMesh(fullPath.c_str());
}

Mesh::~Mesh()
{
	delete this;
}
