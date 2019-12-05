#pragma once
#include <irrlicht.h>
//#include <windows.h>
#include <WinSock2.h>
using namespace irr;
class IrrInclude
{
public:
	static IrrlichtDevice* device;
	static scene::ISceneManager* sceneManager;
	static video::IVideoDriver* driver;
	static gui::IGUIEnvironment* guienv;
	static scene::ICameraSceneNode* camera;
	static scene::IAnimatedMesh* mesh;
	static scene::ISceneNode* node;
	static scene::IAnimatedMeshSceneNode* Model;
	IrrInclude();
	~IrrInclude();
};

