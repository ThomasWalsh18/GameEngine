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
int main(int argc, char* argv[])
{
	GameEngine::init();
	GameEngine::quit();
	return 0;
}