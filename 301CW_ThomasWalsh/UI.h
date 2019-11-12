#pragma once
#include "subSystem.h"
#include <windows.h>
#include <windowsx.h>
#include "GameEngine.h"

class UI: public subSystem
{
public:
	UI();
	~UI();
	void init();
	void addMainChar(Event* toAdd);
	void update();
	Entity* MainCharacter;
	
	HBRUSH g_hbrBack;
	HPEN   g_hpenFore;
	POINTS g_oldPoint;
	MSG messages;

	LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wp, LPARAM lp);
	void wmMouseMove(HWND hwnd, WPARAM wp, LPARAM lp);
	void wmLButtonDown(HWND hwnd, WPARAM wp, LPARAM lp);
	void wmLButtonUp(HWND hwnd, WPARAM wp, LPARAM lp);
};

