#pragma once

//#ifdef _IRR_WINDOWS_
//#pragma comment(lib, "Irrlicht.lib")
//#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
//#endif
#include "subSystem.h"
#include <glm.hpp>
#include <iostream>
#include "GameEngine.h"
#include "CameraEntitiy.h"
#include "EntityEnum.h"

#include <irrlicht.h>



using namespace irr;
class Graphics : public subSystem
{
private:
	const int WIDTH = 1600;
	const int HEIGHT = 900;
public:

	Entity* Camera;// = new Entity(glm::vec3(0, 0, 0));
	int lastFPS = -1;
	static IrrlichtDevice* device;
	video::IVideoDriver* driver;
	static scene::ISceneManager* sceneManager;
	gui::IGUIEnvironment* guienv;
	scene::IAnimatedMesh* mesh;
	scene::ISceneNode* node;
	scene::ICameraSceneNode* camera; 
	scene::IAnimatedMeshSceneNode* Model;

	Graphics();
	~Graphics();
	void addEvent(Event e);
	//For each function pointer I need to pass in the same things
	//This is okay as I am only dealing with the graphics here
	void(*functions[1])(Event*, int , float );
	std::vector <Event> events;
	void Draw(Entity* entity);
	void init();
	void update();

};

