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
	Graphics();
	~Graphics();
	void Draw();
	void init();
	void update();
	int GetWidth();

	static bool firstMove;
	static int lastX;
	static int lastY;
	static float pitch;
	static float yaw;
	static float sensitivity;
	static glm::vec3 cameraFront;

	int lastFPS = -1;
	std::vector <Event> events;

	Entity* Camera;

	//For each function pointer I need to pass in the same things
	//This is okay as I am only dealing with the graphics here
	void(*functions[1])(Event*);

};

