#pragma once
#include "subSystem.h"
class Physics : public subSystem
{
public:
	Physics();
	~Physics();
	void init();
	void update();

};

