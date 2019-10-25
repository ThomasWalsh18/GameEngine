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
	void(*functions[1])(Entity*);
	std::vector <Event> events;
	std::vector <Entity*> entites;
	void Draw(Entity* entity);
	void init();
	void update();

};

