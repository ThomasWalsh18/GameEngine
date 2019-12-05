#pragma once
#include "subSystem.h" 
#include <windows.h>
#include <windowsx.h>
#include "GameEngine.h"

class UI : public subSystem
{
public:
	UI();
	~UI();
	void init();
	void addMainChar(Event* toAdd);
	void update();
	Entity* MainCharacter;
	POINT p;
	int lastx = -1;
	int lasty = -1;

	bool level1 = false;
	bool level2 = false;
};

