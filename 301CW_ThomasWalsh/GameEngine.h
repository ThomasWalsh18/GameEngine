#pragma once
#include "subSystem.h"
#include <vector>
class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	std::vector<subSystem*> SubSystems;
	void init();
	void update();
	void quit();
};

