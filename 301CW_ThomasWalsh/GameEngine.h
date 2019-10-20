#pragma once
#include "subSystem.h"
#include "EventQueue.h"
#include "Graphics.h"
#include "UI.h"
#include <vector>

class GameEngine
{
private:
	
public:
	GameEngine();
	~GameEngine();
	static EventQueue* Queue;
	static std::vector<subSystem*> SubSystems;
	static void init();
	static void update();
	static void quit();
};

