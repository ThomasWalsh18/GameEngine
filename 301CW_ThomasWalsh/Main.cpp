#include <iostream>
#include "GameEngine.h"

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
	bool quit = false;
	GameEngine* Engine = new GameEngine();
	subSystem* graphics = new Graphics();
	Engine->SubSystems.push_back(graphics);


	Engine->init();
	while (!quit) {
		Engine->update();
		//cout << "Main Update" << endl;
	}

	Engine->quit();
	
	return 0;
}