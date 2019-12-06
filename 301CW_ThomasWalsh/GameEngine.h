#pragma once
#include "subSystem.h"
#include "Graphics.h"
#include "UI.h"
#include "Physics.h"
#include "AssetManager.h"
#include "Entity.h"
#include "moveEntity.h"
#include "CameraEntitiy.h"
#include "Audio.h"
#include "LUAData.h"

#include "Multiplayer.h"

#include <vector>
#include <iostream>
#include <map>

class GameEngine
{
private:
	
public:
	GameEngine();
	~GameEngine();
	static std::vector<Event*> eventQueue;
	static std::vector<Entity*> entities;
	static std::vector<subSystem*> SubSystems;           
	static std::map<std::string, Mesh*> Meshes;
	static bool exitLoop;
	static bool exitLoopSet();
	static inline bool exitLoopGet() {
		return exitLoop;
	}
	static void init();
	static void update();
	static void quit();

	static int width;
	static int height;
	static std::string title;
};

