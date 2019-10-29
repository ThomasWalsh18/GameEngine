#include "UI.h"

/*-
UI user interaction
Fule
Ammo
Health
Menus
*/

UI::UI()
{
}

UI::~UI()
{


}

void UI::init()
{

}

void UI::update()
{
	if (GetKeyState('A') & 0x0800) { // to stop toggle
		Event* left = new Event(EventTypeEnum(0));
		left->eventInfo.dir = 2;
		left->eventInfo.speed = 1;
		GameEngine::eventQueue.push_back(left);
		std::cout << "Event add leftward" << std::endl;
	}
	if (GetKeyState('D') & 0x0800) {	
		Event* right = new Event(EventTypeEnum(0));
		right->eventInfo.dir = -2;
		right->eventInfo.speed = 1;
		GameEngine::eventQueue.push_back(right);
		std::cout << "Event add rightward" << std::endl;

	}
	if (GetKeyState('W') & 0x0800) {
		Event* forward = new Event(EventTypeEnum(0));
		forward->eventInfo.dir = -1;
		forward->eventInfo.speed = 1;
		GameEngine::eventQueue.push_back(forward);
		std::cout << "Event add forward" << std::endl;
	}
	if (GetKeyState('S') & 0x0800) {
		Event* backward = new Event(EventTypeEnum(0));
		backward->eventInfo.dir = 1;
		backward->eventInfo.speed = 1;
		GameEngine::eventQueue.push_back(backward);
		std::cout << "Event add backward" << std::endl;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x80000000 ) {
		Event* upward = new Event(EventTypeEnum(0));
		upward->eventInfo.dir = -3;
		upward->eventInfo.speed = 1;
		GameEngine::eventQueue.push_back(upward);
		std::cout << "Event add upward" << std::endl;
	}
	if (GetKeyState('Q') & 0x800 ) {
		Event* upward = new Event(EventTypeEnum(0));
		upward->eventInfo.dir = 3;
		upward->eventInfo.speed = 1;
		GameEngine::eventQueue.push_back(upward);
		std::cout << "Event add downward" << std::endl;
	}
	

}
