#include "UI.h"

/*-
UI user interaction
Fule
Ammo
Health
Menus
*/

UI::UI()
{
}

UI::~UI()
{
}

void UI::init()
{
	
}

void UI::update()
{

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT)
		{
			GameEngine::quit();
		}
		else if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
			{
				Event* forward = new Event(EventTypeEnum(0));
				forward->eventInfo.dir = 1;
				forward->eventInfo.speed = 10;
				GameEngine::eventQueue.push_back(forward);
				std::cout << "Event add forward" << std::endl; 
			 }
				break;
			case SDLK_DOWN:
			{
				Event* backward = new Event(EventTypeEnum(0));
				backward->eventInfo.dir = -1;
				backward->eventInfo.speed = 10;
				GameEngine::eventQueue.push_back(backward);
				std::cout << "Event add backward" << std::endl;
			}
	
				break;
			case SDLK_LEFT:
			{
				Event* left = new Event(EventTypeEnum(0));
				left->eventInfo.dir = 2;
				left->eventInfo.speed = 10;
				GameEngine::eventQueue.push_back(left);
				std::cout << "Event add leftward" << std::endl;
			}

				break;
			case SDLK_RIGHT:
			{
				Event* right = new Event(EventTypeEnum(0));
				right->eventInfo.dir = -2;
				right->eventInfo.speed = 10;
				GameEngine::eventQueue.push_back(right);
				std::cout << "Event add rightward" << std::endl;
			}
				break;
			case SDLK_ESCAPE:
				SDL_Quit();
				break;
			}
		}
	}
}
