#pragma once
#include "Graphics.h"
#include <string>

class Mesh
{
public:
	Mesh(std::string fullPath);
	~Mesh();
	std::string path;
	scene::IAnimatedMesh* model;
	scene::IAnimatedMeshSceneNode* mesh;

};

