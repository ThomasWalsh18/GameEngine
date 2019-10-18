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
	rect.w = 198.0f;
	rect.h = 198.0f;
	rect.x = 600.0f;
	rect.y = 2.0f;
	outLine.w = 201.0f;
	outLine.h = 201.0f;
	outLine.x = 598.0f;
	outLine.y = 1.0f;

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
				outLine.y += -5;
				break;
			case SDLK_DOWN:
				rect.y += 5;
				outLine.y += 5;
				break;
			case SDLK_LEFT:
				rect.x += -5;
				outLine.x += -5;
				break;
			case SDLK_RIGHT:
				rect.x += 5;
				outLine.x += 5;
				break;
			case SDLK_ESCAPE:
				break;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
		SDL_RenderFillRect(renderer, &outLine);
		SDL_RenderPresent(renderer);
		//std::cout << "Graphics Updated" << std::endl;
	}
}
