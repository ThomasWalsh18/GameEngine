#pragma once
#include <iostream>
#include "Event.h"

class subSystem
{
public:
	subSystem();
	virtual ~subSystem();
	virtual void init();
	virtual void update();

};