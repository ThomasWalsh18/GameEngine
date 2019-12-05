#pragma once

#include "GameEngine.h"
#include "Mesh.h"

class AssetManager : public subSystem
{
public:
	AssetManager();
	void init();
	~AssetManager();
	std::string modelname;
	static void LoadModel(std::string fileName, std::string modelName);

	static Mesh* GetModel(std::string modelName);
};

