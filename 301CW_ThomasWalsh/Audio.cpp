#include "Audio.h"
/*
	- Audio
		Shooting
		tank moving

*/

Audio::Audio()
{
}

Audio::~Audio()
{

}

void Audio::init()
{
	engine = irrklang::createIrrKlangDevice();
	engine->play2D("./media/ThisiswarNES.wav", true);
}

void Audio::update()
{
	if (GameEngine::eventQueue.size() != 0) { // if event Q is populated
		for (int i = 0; i < GameEngine::eventQueue.size(); i++) {	// for each event, then for each sub system in each event
			for (int j = 0; j < GameEngine::eventQueue[i]->mySubs.size(); j++) {
				if (GameEngine::eventQueue[i]->mySubs[j] == SubSystemEnum(4)) { // check to see if it need the current subsystem
					functions[int(GameEngine::eventQueue[i]->functPoint)](GameEngine::eventQueue[i]);
					GameEngine::eventQueue[i]->mySubs.erase(GameEngine::eventQueue[i]->mySubs.begin() + j);
				}
			}
		}
	}
}
