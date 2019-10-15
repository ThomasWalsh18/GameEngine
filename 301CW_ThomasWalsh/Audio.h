#pragma once
#include "subSystem.h"
class Audio : public subSystem
{
public:
	Audio();
	~Audio();
	void init();
	void update();
};

