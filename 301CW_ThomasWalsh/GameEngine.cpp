#include "GameEngine.h"
GameEngine::GameEngine() {

}
GameEngine::~GameEngine()
{
}

void GameEngine::init() {
	subSystem* graphics = new Graphics();
	SubSystems.push_back(graphics);
	subSystem* ui = new UI();
	SubSystems.push_back(ui);
	for (int i = 0; i < SubSystems.size(); i++) {
		SubSystems[i]->init();
	}
	update();
}

void GameEngine::update()
{
	while (!Queue->exitLoop) {
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


}

void GameEngine::quit()
{
	for (int i = 0; i < SubSystems.size(); i++) {
		
		SubSystems[i]->~subSystem();
	}
}
