#include "AssetManager.h"
AssetManager::AssetManager() 
{

}

void AssetManager::init()
{

	/*

	I can load each model here before Lua however I decided to load each model as and when we needed it from lu

	LoadModel("cannon.obj", "cannon");
	LoadModel("Test.obj", "Test");
	LoadModel("IronGiant.X", "Iron");
	LoadModel("terrain3.X", "Map");

	LoadModel("Vheical.X", "Vheical");
	LoadModel("IronGiantA.X", "Giant");
	*/

}


AssetManager::~AssetManager()
{
}

void AssetManager::LoadModel(std::string fileName, std::string modelName)
{
	/*
	Open file at filepath then make a new model
	with this data then add to map with name modelname, and pointer to model we just made

	I use a map so that each model can be identified easier by not using the file path every time
	*/
	std::string fullPath = "./media/" + fileName;
	Mesh* mesh = new Mesh(fullPath);
	GameEngine::Meshes.emplace(modelName, mesh);
	
}

Mesh* AssetManager::GetModel(std::string modelName)
{
	//if modelname in map, return it, else nullptr
	for (std::map<std::string, Mesh*>::iterator i = GameEngine::Meshes.begin(); i != GameEngine::Meshes.end(); i++) {
		if (i->first == modelName) {
			return i->second;
		}
	}
	return nullptr;
}
