#pragma once
#include "subSystem.h"
#include "GameEngine.h"
#include <irrKlang.h>

class Audio : public subSystem
{
public:
	Audio();
	~Audio();
	void init();
	void update();
	void(*functions[5])(Event*);
	irrklang::ISoundEngine* engine;


};

