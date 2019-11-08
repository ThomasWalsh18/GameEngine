#pragma once
#include <map>
#include "Mesh.h"

class AssestManager : public subSystem
{
public:
	AssestManager();
	void init();
	static std::map<std::string, Mesh*> Meshes;
	~AssestManager();
	std::string modelname;
	void LoadModel(std::string fileName, std::string modelName);

	static Mesh* GetModel(std::string modelName);
};

