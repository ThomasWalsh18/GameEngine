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
bool GameEngine::exitLoop = false;

void GameEngine::init() {

	subSystem* graphics = new Graphics();
	GameEngine::SubSystems.push_back(graphics);
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
		/*
		if (eventQueue->eventQueue.size() != 0) {
			for (int i = 0; i < eventQueue->eventQueue.size(); i++) {
				if (eventQueue->eventQueue[i].mySubs[i] == SubSystemEnum(0)) {
					graphics->addEvent(eventQueue->eventQueue[i]);
				}
			}
		}
		*/
		//cout << "Main Update" << endl;
}

void GameEngine::quit()
{
	GameEngine::exitLoopSet();
	for (int i = 0; i < SubSystems.size(); i++) {
		
		SubSystems[i]->~subSystem();
	}
}
