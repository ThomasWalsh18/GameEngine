#include "GameEngine.h"
GameEngine::GameEngine() {

}
GameEngine::~GameEngine()
{
}
bool GameEngine::exitLoopSet()
{
	if (exitLoop == false) {
		exitLoop = true;
	}
	else {
		exitLoop = false;
	}
	return exitLoop;
}
std::vector<subSystem*> GameEngine::SubSystems;
std::vector<Event*> GameEngine::eventQueue;
std::vector<Entity*> GameEngine::entities;
std::map<std::string, Mesh*> GameEngine::Meshes;
bool GameEngine::exitLoop = false;

void GameEngine::init() {
	subSystem* physics = new Physics();
	subSystem* graphics = new Graphics();
	subSystem* assetMan = new AssetManager();
	subSystem* logic = new GamePlay();
	subSystem* ui = new UI();
	subSystem* audio = new Audio();
	SubSystems.push_back(assetMan);
	SubSystems.push_back(graphics);
	SubSystems.push_back(physics);
	SubSystems.push_back(logic);
	SubSystems.push_back(ui);
	SubSystems.push_back(audio);

	for (int i = 0; i < SubSystems.size(); i++) {
		SubSystems[i]->init();
	}
}

void GameEngine::update()
{
	for (int i = 0; i < SubSystems.size(); i++) {
		SubSystems[i]->update();
	}
	for (int i = 0; i < eventQueue.size(); i++) {
		if (GameEngine::eventQueue[i]->functPoint == EventTypeEnum(2)) {
			GameEngine::quit();
		}
		if (GameEngine::eventQueue[i]->mySubs.size() == 0) {
			GameEngine::eventQueue.erase(GameEngine::eventQueue.begin() + i);
		}
	}
}

void GameEngine::quit()
{
	GameEngine::exitLoopSet();
	for (int i = 0; i < SubSystems.size(); i++) {
		
		SubSystems[i]->~subSystem();
	}
}
