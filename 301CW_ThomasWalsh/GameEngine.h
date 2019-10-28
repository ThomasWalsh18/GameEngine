#pragma once
#include "subSystem.h"
#include "Graphics.h"
#include "UI.h"
#include "Physics.h"
#include "GamePlay.h"
#include "Entity.h"
#include <vector>

class GameEngine
{
private:
	
public:
	GameEngine();
	~GameEngine();
	static std::vector<Event*> eventQueue;
	static std::vector<Entity*> entities;
	static bool exitLoop;
	static bool exitLoopSet();
	static inline bool exitLoopGet() {
		return exitLoop;
	}
	static std::vector<subSystem*> SubSystems;
	static void init();
	static void update();
	static void quit();
};

