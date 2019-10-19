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

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT)
		{
			this->~Graphics();
		}
		else if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				rect.y += -5;
				break;
			case SDLK_DOWN:
				rect.y += 5;
				break;
			case SDLK_LEFT:
				rect.x += -5;
				break;
			case SDLK_RIGHT:
				rect.x += 5;
				break;
			case SDLK_ESCAPE:
				break;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
		//std::cout << "Graphics Updated" << std::endl;
	}
}
