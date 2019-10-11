#include <iostream>
#include "subSystem.h"
#include "GameEngine.h"
/*
classes and then make all subsystem classes
then put it all into each of the relevalt subsystems

create an array of subsystems given index subsystem zero is the same as enum 0

gameplay subsystem

Game Should be:
tank management system

*/
using namespace std;

int main(int argc, char* argv[])
{
	bool quit = false;
	GameEngine* Engine = new GameEngine();
	Engine->init();
	while (!quit) {
		Engine->update();
		cout << "Hello World!" << endl;
	}

	Engine->quit();
	
	return 0;
}