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
			this->~UI();
		}
		else if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
			{
			//Event* forward = new Event(EventTypeEnum(0));
			//GameEngine::Queue->eventQueue.push_back(forward);
			std::cout << "Event add forward" << std::endl; 
			}
				break;
			case SDLK_DOWN:
				std::cout << "Event add backward" << std::endl;
				break;
			case SDLK_LEFT:
				std::cout << "Event add leftward" << std::endl;
				break;
			case SDLK_RIGHT:
				std::cout << "Event add rightward" << std::endl;
				break;
			case SDLK_ESCAPE:
				SDL_Quit();
				break;
			}
		}
	}
}
