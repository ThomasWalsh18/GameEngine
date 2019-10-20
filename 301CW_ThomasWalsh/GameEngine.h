#pragma once
#include "subSystem.h"
#include "Graphics.h"
#include "UI.h"
#include <vector>

class GameEngine
{
private:
	
public:
	GameEngine();
	~GameEngine();
	static std::vector<Event*> eventQueue;
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

