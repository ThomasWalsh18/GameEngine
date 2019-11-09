#pragma once
#include <string>
#include "IrrInclude.h"
class Mesh
{
public:
	
	Mesh(std::string fullPath);
	~Mesh();
	std::string path;
	scene::IAnimatedMesh* model;
	scene::IAnimatedMeshSceneNode* animatedSceneNode;

};

