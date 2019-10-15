#include "GameEngine.h"
GameEngine::GameEngine() {

}
GameEngine::~GameEngine()
{
}
void GameEngine::init() {
	for (int i = 0; i < SubSystems.size(); i++) {
		SubSystems[i]->init();
	}
}

void GameEngine::update()
{
	for (int i = 0; i < SubSystems.size(); i++) {
		SubSystems[i]->update();
	}
}

void GameEngine::quit()
{
	for (int i = 0; i < SubSystems.size(); i++) {
		
		SubSystems[i]->~subSystem();
	}
}
