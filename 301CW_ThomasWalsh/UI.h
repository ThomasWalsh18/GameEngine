#pragma once
#include "subSystem.h"
#include <windows.h>
#include "GameEngine.h"

class UI: public subSystem
{
public:
	UI();
	~UI();
	void init();
	void addMainChar(Event* toAdd);
	void update();
	Entity* MainCharacter;
};

