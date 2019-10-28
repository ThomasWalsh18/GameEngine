#pragma once
#include "subSystem.h"
#include <glm.hpp>
#include <SDL.h>
#include <SDL_main.h>
#include <iostream>
#include "GameEngine.h"
#include "RectEntity.h"


class Graphics : public subSystem
{
private:
	const int WIDTH = 1600;
	const int HEIGHT = 900;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Surface* surface = nullptr; 
	SDL_Event e;
	SDL_Rect rect;
public:
	Graphics();
	~Graphics();
	void addEvent(Event e);
	//For each function pointer I need to pass in the same things
	//This is okay as I am only dealing with the graphics here
	void(*functions[1])(Entity*, int , float );
	std::vector <Event> events;
	void Draw(Entity* entity);
	void init();
	void update();

};

