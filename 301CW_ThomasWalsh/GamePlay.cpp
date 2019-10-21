#include "GamePlay.h"
/*
	- Gameplay
		Resourse management system based on a tank, sort of first person shooter style but with fuel and ammo etc
		maybe also manage oxygen because you are on a forgien planet and you will lose oxygen when you get shot
*/


GamePlay::GamePlay() {

}

GamePlay::~GamePlay()
{
}

void GamePlay::init()
{
}

void GamePlay::update()
{
	if (GameEngine::eventQueue.size() != 0) { // if event Q is populated
		for (int i = 0; i < GameEngine::eventQueue.size(); i++) {	// for each event, then for each sub system in each event
			for (int j = 0; j < GameEngine::eventQueue[i]->mySubs.size(); j++) {
				if (GameEngine::eventQueue[i]->mySubs[j] == SubSystemEnum(1)) { // check to see if it need the current subsystem
					std::cout << "Seen event Game play" << std::endl;
					GameEngine::eventQueue[i]->mySubs.erase(GameEngine::eventQueue[i]->mySubs.begin() + j);
					//do the actual stuff now like checking to see what it is for example is it a move event
					//if event enum type == 0 move. Dont know how to do the different speeds and or directions without load of different events

				
				}
			}
		}
	}
}
