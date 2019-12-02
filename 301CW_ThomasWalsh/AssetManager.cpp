#include "AssetManager.h"
AssetManager::AssetManager() 
{

}

void AssetManager::init()
{
	//load all models
	LoadModel("cannon.obj", "cannon");
	LoadModel("Test.obj", "Test");
	LoadModel("IronGiant.X", "Iron");
	LoadModel("terrain3.X", "Map");

	LoadModel("Vheical.X", "Vheical");
	LoadModel("IronGiantA.X", "Giant");
	//LoadModel("TestScene.obj", "Map");

}


AssetManager::~AssetManager()
{
}

void AssetManager::LoadModel(std::string fileName, std::string modelName)
{
	//open file at filepath
	//Make a new model with this data
	//add to map with name modelname, and model pointer to one we just made
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
