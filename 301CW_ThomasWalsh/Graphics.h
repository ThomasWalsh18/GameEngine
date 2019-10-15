#pragma once
#include "subSystem.h"
#include <glm.hpp>
#include <SDL.h>
#include <SDL_main.h>
#include <iostream>

class Graphics : public subSystem
{
private:
	const int WIDTH = 1600;
	const int HEIGHT = 900;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Surface* surface = nullptr; 
public:
	Graphics();
	~Graphics();
	void init();
	void update();
};

