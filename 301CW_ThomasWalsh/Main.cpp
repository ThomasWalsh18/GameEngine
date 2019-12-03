#include "GameEngine.h"

int main(int argc, char* argv[])
{
	GameEngine::init();
	while (!GameEngine::exitLoopGet()) {
		GameEngine::update();
	}
	GameEngine::quit();
	return 0;
}