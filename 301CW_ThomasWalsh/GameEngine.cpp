#include "GameEngine.h"
GameEngine::GameEngine() {

}
GameEngine::~GameEngine()
{
}
bool GameEngine::exitLoopSet()
{
	/*
	This setter is for the bool to exit the game
	*/
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
std::vector<Entity*> GameEngine::entities;
std::map<std::string, Mesh*> GameEngine::Meshes;
bool GameEngine::exitLoop = false;


/*
This can be done by loading LUA up in graphics, 
However I have one LUA controller where I wanted all my LUA scripts
These are also set to deafult values
*/
int GameEngine::width = 100;
int GameEngine::height = 100;
std::string GameEngine::title = "Default";

void GameEngine::init() {
	/*
	Create each subsystem 
	Then call all the inits
	*/
	subSystem* LUA = new LUAData();
	subSystem* physics = new Physics();
	subSystem* graphics = new Graphics();
	subSystem* assetMan = new AssetManager();
	subSystem* ui = new UI();
	subSystem* audio = new Audio();

	subSystem* multiPlayer = new Multiplayer();

	SubSystems.push_back(assetMan);
	SubSystems.push_back(LUA);
	SubSystems.push_back(graphics);
	SubSystems.push_back(physics);
	SubSystems.push_back(ui);
	SubSystems.push_back(audio);

	SubSystems.push_back(multiPlayer);

	for (int i = 0; i < SubSystems.size(); i++) {
		SubSystems[i]->init();
	}
}

void GameEngine::update()
{
	/*
	Call each subsystems update

	The eventqueue:
		In the engines update I will look thorugh each event in the queue and remove it if it has no subsystems in it
		Then also check to see if it is the close event

		Each subsystem will then also check the event queue
		however they are checking the events subsystems and if their subsystem enum is referenced
		If they see their subsystem enum the event is trying to talk to them
		They will then run what ever function the event is trying to access by use of function pointers
		Then after the function is called the subsystem will be removed from the subsystem list for that event
	*/
	for (int i = 0; i < SubSystems.size(); i++) {
		SubSystems[i]->update();
	}
	for (int i = 0; i < eventQueue.size(); i++) {
		if (GameEngine::eventQueue[i]->functPoint == EventTypeEnum(2)) {
			GameEngine::quit();
		}
		if (GameEngine::eventQueue[i]->mySubs.size() == 0) {
			GameEngine::eventQueue.erase(GameEngine::eventQueue.begin() + i);
		}
	}
}

void GameEngine::quit()
{
	GameEngine::exitLoopSet();
	for (int i = 0; i < SubSystems.size(); i++) {
		
		SubSystems[i]->~subSystem();
	}
}
