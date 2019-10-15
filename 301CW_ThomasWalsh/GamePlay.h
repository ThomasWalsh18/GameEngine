#pragma once
#include "subSystem.h"

class GamePlay  : public subSystem 
{
public:
	GamePlay();
	~GamePlay();
	void init();
	void update();
};

