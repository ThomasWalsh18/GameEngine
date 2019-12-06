#include "Mesh.h"
#include <iostream>
Mesh::Mesh(std::string fullPath)
{
	/*
	When a mesh is created I will pass in a path to where I can find the mesh
	And then get the mesh
	*/
	this->path = fullPath;
	this->model = IrrInclude::device->getSceneManager()->getMesh(fullPath.c_str());
}
void Mesh::destroy() {

}
Mesh::~Mesh()
{
}
