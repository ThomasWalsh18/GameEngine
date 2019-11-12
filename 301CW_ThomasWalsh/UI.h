#pragma once
#include "subSystem.h"
#include <windows.h>
#include <windowsx.h>
#include "GameEngine.h"

class UI : public subSystem
{
public:
	UI();
	~UI();
	void init();
	void addMainChar(Event* toAdd);
	void update();
	Entity* MainCharacter;

	HBRUSH g_hbrBack;
	POINTS g_oldPoint;
	BOOL do_mouse_move = FALSE;
	//char szClassName[] = "MouseTrack";
	

	LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
	void wmMouseMove(HWND, WPARAM, LPARAM);
	void Do_Draw(HDC, WPARAM, LPARAM);
	void wmLButtonDown(HWND, WPARAM, LPARAM);
	void wmLButtonUp(HWND, WPARAM, LPARAM);
	void wmKeyDown(HWND, WPARAM, LPARAM);
	void wmLButtonDblClk(HWND, WPARAM, LPARAM);
};

