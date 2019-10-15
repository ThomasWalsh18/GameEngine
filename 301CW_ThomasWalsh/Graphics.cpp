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
	std::cout << "Graphics Init" << std::endl;
}

void Graphics::update()
{
	std::cout << "Graphics Updated" << std::endl;
}
