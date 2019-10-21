#include "Graphics.h"
/*
	- Graphics
		The tank itself
		other tanks
		terrain
		sky
*/

Graphics::Graphics()
{
	std::cout << "Graphics Created" << std::endl;
}

Graphics::~Graphics()
{
	//Quit SDL subsystems

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();
	std::cout << "Graphics has deleted" << std::endl;
}

void Graphics::addEvent(Event e)
{
	events.push_back(e);
}

void Graphics::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Error initilsing. SDL Error: %s \n", SDL_GetError());
	}
	else {
		window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		surface = SDL_GetWindowSurface(window);
		if (window == NULL)
		{
			printf("could not create window: %s\n", SDL_GetError());
		}
		else {
	
			SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));
			std::cout << "Graphics Init" << std::endl;
		}
		
	}

	rect.x = 0;
	rect.w = 190;
	rect.h = 198;
	rect.x = 600;
	rect.y = 2;


}

void Graphics::update()
{
	SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
	if (GameEngine::eventQueue.size() != 0) { // if event Q is populated
		for (int i = 0; i < GameEngine::eventQueue.size(); i++) {	// for each event, then for each sub system in each event
			for (int j = 0; j < GameEngine::eventQueue[i]->mySubs.size(); j++) {
				if (GameEngine::eventQueue[i]->mySubs[j] == SubSystemEnum(2)) { // check to see if it need the current subsystem
					std::cout << "Seen event graphics" << std::endl; 
					GameEngine::eventQueue[i]->mySubs.erase(GameEngine::eventQueue[i]->mySubs.begin() + j);
					//do the actual stuff now like checking to see what it is for example is it a move event
					//if event enum type == 0 move. Dont know how to do the different speeds and or directions without load of different events
				}
			}
		}
	}
}
