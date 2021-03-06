#include "AssestManager.h"
AssestManager::AssestManager() 
{

}

void AssestManager::init()
{
	//load all models
	LoadModel("cannon.obj", "cannon");
}


AssestManager::~AssestManager()
{
}

void AssestManager::LoadModel(std::string fileName, std::string modelName)
{
	//open file at filepath
	//Make a new model with this data
	//add to map with name modelname, and model pointer to one we just made
	std::string fullPath = "./media/" + fileName;
	Mesh* mesh = new Mesh(fullPath);
	GameEngine::Meshes.emplace(modelName, mesh);
	
}

Mesh* AssestManager::GetModel(std::string modelName)
{
	//if modelname in map, return it, else nullptr
	for (std::map<std::string, Mesh*>::iterator i = GameEngine::Meshes.begin(); i != GameEngine::Meshes.end(); i++) {
		if (i->first == modelName) {
			return i->second;
		}
	}
	return nullptr;
}
