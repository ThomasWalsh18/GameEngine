#pragma once
#include "subSystem.h"
#include "GameEngine.h"
#include "btBulletDynamicsCommon.h"
class Physics : public subSystem
{
public:
	Physics();
	~Physics();
	void init();
	void update();
	void(*functions[1])(Event*, int, float);
};

