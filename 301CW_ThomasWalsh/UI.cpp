#include "UI.h"

/*-
UI user interaction
	Fuel
	Ammo
	Health
	Menus
	gainput
*/

UI::UI()
{

}

void UI::wmMouseMove(HWND hwnd, WPARAM wp, LPARAM lp) {
	POINTS p;
	HDC hdc;
	std::cout << " Mouse moved" << std::endl;
	//if (wp != MK_LBUTTON) return;
//https://stackoverflow.com/questions/50691580/wm-mousemove-get-x-lparam-and-get-y-lparam-catch-wrong-coordinates
	p = MAKEPOINTS(lp);
	hdc = GetDC(hwnd);
	SelectObject(hdc, g_hpenFore);
	MoveToEx(hdc, g_oldPoint.x, g_oldPoint.y, 0);
	LineTo(hdc, p.x, p.y);
	g_oldPoint = p;
	ReleaseDC(hwnd, hdc);
}
void UI::wmLButtonDown(HWND hwnd, WPARAM wp, LPARAM lp) {
	g_oldPoint = MAKEPOINTS(lp);
	SetCapture(hwnd);
}

void UI::wmLButtonUp(HWND hwnd, WPARAM wp, LPARAM lp) {
	ReleaseCapture();
}

LRESULT CALLBACK UI::WindowProcedure(HWND hwnd, UINT message, WPARAM wp, LPARAM lp)
{
	switch (message) {
	case WM_MOUSEMOVE:
		wmMouseMove(hwnd, wp, lp);
		break;
	case WM_LBUTTONDOWN:
		wmLButtonDown(hwnd, wp, lp);
		break;
	case WM_LBUTTONUP:
		wmLButtonUp(hwnd, wp, lp);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wp, lp);
	}
	return 0;
}
UI::~UI()
{
	
}

void UI::init()
{
	if (GameEngine::entities.size() != 0) {
		for (int i = 0; i < GameEngine::entities.size(); i++) {
			if (GameEngine::entities[i]->type == EntityEnum(1)) { //atm its just the character
				MainCharacter = GameEngine::entities[i];
			}
		}
	}
	else {
		std::cout << "-----------------No main character error---------------" << std::endl;
		MainCharacter = nullptr;
	}
}
void UI::addMainChar(Event* toAdd) {
	toAdd->eventInfo.affEntities.push_back(MainCharacter);
}


void UI::update()
{
	if (GetKeyState('A') & 0x0800) { // to stop toggle
		Event* left = new Event(EventTypeEnum(0));
		// dir done in physics eventyally as I can store instead a char of the key that was pressed
		// speed can be done by the game logic clas giving the main character enum a speed of 1
		left->eventInfo.dir = 2;
		left->eventInfo.speed = 1;
		////////////////////////////
		addMainChar(left);
		GameEngine::eventQueue.push_back(left);
		std::cout << "Event add leftward" << std::endl;
		////////////////////////////
	}
	if (GetKeyState('D') & 0x0800) {	
		Event* right = new Event(EventTypeEnum(0));
		right->eventInfo.dir = -2;
		right->eventInfo.speed = 1;
		addMainChar(right);
		GameEngine::eventQueue.push_back(right);
		std::cout << "Event add rightward" << std::endl;

	}
	if (GetKeyState('W') & 0x0800) {
		Event* forward = new Event(EventTypeEnum(0));
		forward->eventInfo.dir = -1;
		forward->eventInfo.speed = 1;
		addMainChar(forward);
		GameEngine::eventQueue.push_back(forward);
		std::cout << "Event add forward" << std::endl;
	}
	if (GetKeyState('S') & 0x0800) {
		Event* backward = new Event(EventTypeEnum(0));
		backward->eventInfo.dir = 1;
		backward->eventInfo.speed = 1;
		addMainChar(backward);
		GameEngine::eventQueue.push_back(backward);
		std::cout << "Event add backward" << std::endl;
	}
	if (GetKeyState('O') & 0x0800) {
		GameEngine::entities[GameEngine::entities.size()-2]->position += glm::vec3(0.0f, -1.0f, 0.0f);
	}
	if (GetKeyState('P') & 0x0800) {
		GameEngine::entities[GameEngine::entities.size()-1]->position += glm::vec3(0.0f, -1.0f, 0.0f);
	}
	if (GetKeyState('I') & 0x0800) {
		GameEngine::entities[GameEngine::entities.size()-3]->position += glm::vec3(0.0f, -1.0f, 0.0f);
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x80000000 ) {
		Event* upward = new Event(EventTypeEnum(0));
		upward->eventInfo.dir = -3;
		upward->eventInfo.speed = 1;
		addMainChar(upward);
		GameEngine::eventQueue.push_back(upward);
		std::cout << "Event add upward" << std::endl;
	}
	if (GetKeyState('Q') & 0x800 ) {
		Event* downward = new Event(EventTypeEnum(0));
		downward->eventInfo.dir = 3;
		downward->eventInfo.speed = 1;
		addMainChar(downward);
		GameEngine::eventQueue.push_back(downward);
		std::cout << "Event add downward" << std::endl;
	}
	if (GetMessage(&messages, NULL, 0, 0)) {
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}

}
