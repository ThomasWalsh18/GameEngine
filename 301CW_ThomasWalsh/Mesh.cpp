#include "Mesh.h"
#include <iostream>
Mesh::Mesh(std::string fullPath)
{
	this->path = fullPath;
	this->model = IrrInclude::device->getSceneManager()->getMesh(fullPath.c_str());
}
void Mesh::destroy() {
	//this->path = "";
	//this->model = nullptr;
	std::cout << "CLEAR" << std::endl;
	//delete this;
}
Mesh::~Mesh()
{
}
