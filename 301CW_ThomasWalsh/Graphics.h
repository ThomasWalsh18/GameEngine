#pragma once
#include "subSystem.h"
#include <SDL.h>
#include <SDL_main.h>
#include <iostream>
class Graphics : public subSystem
{
public:
	Graphics();
	~Graphics();
	void init();
	void update();
};

