#pragma once
#include <iostream>
class subSystem
{
public:
	subSystem();
	virtual ~subSystem();
	virtual void init();
	virtual void update();

};