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
bool GameEngine::exitLoop = false;

void GameEngine::init() {
	subSystem* physics = new Physics();
	SubSystems.push_back(physics);
	subSystem* graphics = new Graphics();
	GameEngine::SubSystems.push_back(graphics);
	subSystem* logic = new GamePlay();
	SubSystems.push_back(logic);
	subSystem* ui = new UI();
	SubSystems.push_back(ui);

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
