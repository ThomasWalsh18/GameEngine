#pragma once

#include "subSystem.h"
#include "GameEngine.h"
#include "EntityEnum.h"


#include "IrrInclude.h"

using namespace irr;

class Graphics : public subSystem
{
private:

public:
	video::SExposedVideoData videodata;
	core::stringw text;
	gui::IGUIFont* font;
	Graphics();
	~Graphics();

	void Draw();
	void init();
	void update();

	static bool firstMove;
	static int lastX;
	static int lastY;
	static float pitch;
	static float yaw;
	static float sensitivity;
	static glm::vec3 cameraFront;
	static HWND hWnd;
	
	static Entity* mainChar;

	int lastFPS = -1;
	std::vector <Event> events;

	//For each function pointer I need to pass in the same things
	//This is okay as I am only dealing with the graphics here
	void(*functions[6])(Event*);
	Entity* Camera;

	/*
	Defualt values just incase nothing is accepted from LUA
	*/
	std::string title = "Graphics Default";
	int WIDTH = 1000;
	int HEIGHT = 1000;
};

