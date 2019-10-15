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
	std::cout << "Graphics has deleted" << std::endl;
}

void Graphics::init()
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	surface = SDL_GetWindowSurface(window);
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));
	if (window == NULL)
	{
		printf("could not create window: %s\n", SDL_GetError());
	}
	else {
		std::cout << "Graphics Init" << std::endl;
	}
}

void Graphics::update()
{
	SDL_LockSurface(surface);

	Uint32* pixels = (Uint32*)surface->pixels;

	for (unsigned int x = 0; x < WIDTH; ++x)
	{
		for (unsigned int y = 0; y < HEIGHT; ++y)
		{
			
		}
	}

	SDL_UnlockSurface(surface);
	//Update the surface
	SDL_UpdateWindowSurface(window);
	

	std::cout << "Graphics Updated" << std::endl;
}
