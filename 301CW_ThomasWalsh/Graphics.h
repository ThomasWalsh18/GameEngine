#pragma once

#include "subSystem.h"
#include "GameEngine.h"

#include "EntityEnum.h"

#include "IrrInclude.h"

using namespace irr;
class Graphics : public subSystem
{
private:
	const int WIDTH = 1600;
	const int HEIGHT = 900;
public:

	Entity* Camera;
	int lastFPS = -1;
	Graphics();
	~Graphics();
	void addEvent(Event e);
	//For each function pointer I need to pass in the same things
	//This is okay as I am only dealing with the graphics here
	void(*functions[1])(Event*, int , float );
	std::vector <Event> events;
	void Draw();
	void init();
	void update();

};

