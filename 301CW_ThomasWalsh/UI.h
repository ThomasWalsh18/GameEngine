#pragma once
#include "subSystem.h"
#include <SDL.h>
#include <SDL_main.h>
#include <Windows.h>
#include "GameEngine.h"

class UI: public subSystem
{
public:
	UI();
	~UI();
	void init();
	void update();
	SDL_Event e;
};

