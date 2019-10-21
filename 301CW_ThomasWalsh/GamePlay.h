#pragma once
#include "subSystem.h"
#include "GameEngine.h"

class GamePlay  : public subSystem 
{
public:
	GamePlay();
	~GamePlay();
	void init();
	void update();
};

