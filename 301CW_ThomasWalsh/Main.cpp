#include "GameEngine.h"

int main(int argc, char* argv[])
{
	/*
	Start the Game engine, Update the game engine And close the game engine
	*/
	GameEngine::init();
	while (!GameEngine::exitLoopGet()) {
		GameEngine::update();
	}
	GameEngine::quit();
	return 0;
}