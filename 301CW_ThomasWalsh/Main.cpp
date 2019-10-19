#include <iostream>
#include "EventQueue.h"
#include "GameEngine.h"
#include "SubSystemEnum.h"

/*
classes and then make all subsystem classes
then put it all into each of the relevalt subsystems

create an array of subsystems given index subsystem zero is the same as enum 0

gameplay subsystem

Game Should be:
tank management system

make stuff private and use getters and setters

active subsystem* which means each time we refresh the different varaibles we are allowed to access 

*/
using namespace std;

int main(int argc, char* argv[])
{
	//EventQueue* eventQueue = new EventQueue();
	bool quit = false;
	GameEngine* Engine = new GameEngine();
	subSystem* graphics = new Graphics();
	Engine->SubSystems.push_back(graphics);


	Engine->init();
	while (!quit) {
		/*
		if (eventQueue->eventQueue.size() != 0) {
			for (int i = 0; i < eventQueue->eventQueue.size(); i++) {
				if (eventQueue->eventQueue[i].mySubs[i] == SubSystemEnum(0)) {
					graphics->addEvent(eventQueue->eventQueue[i]);
				}
			}
		} 
		*/
		Engine->update();
		//cout << "Main Update" << endl;
	}

	Engine->quit();
	
	return 0;
}