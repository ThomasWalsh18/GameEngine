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
	if (GetKeyState('Q') & 0x0800 ) {
		Event* downward = new Event(EventTypeEnum(0));
		downward->eventInfo.dir = 3;
		downward->eventInfo.speed = 1;
		addMainChar(downward);
		GameEngine::eventQueue.push_back(downward);
		std::cout << "Event add downward" << std::endl;
	}

	if (GetCursorPos(&p))
	{
		std::cout << " moved" << std::endl;
		std::cout << p.x << std::endl;
		//cursor position now in p.x and p.y
	}
	/*
	if (ScreenToClient(hwnd, &p))
	{
		//p.x and p.y are now relative to hwnd's client area
	}
	*/
}

/*
void UI::mouseMove(int x, int y)
{
	if (firstMouse)
	{
		lastX = x;
		lastY = y;
		firstMouse = false;
	}

	float xoffset = x - lastX;
	float yoffset = lastY - y; // reversed since y-coordinates go from bottom to top
	lastX = x;
	lastY = y;

	float sensitivity = 0.3f; // change able sensitivty higher it is the more sensitive. Better to have a large sensitivy so I can see the whole screen
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (pitch > 89.0f) {
		pitch = 89.0f;
	}
	if (pitch < -89.0f) {
		pitch = -89.0f;
	}

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(front);
	//force mouse to stay inside the window
	int win_w = glutGet(GLUT_WINDOW_WIDTH);
	int win_h = glutGet(GLUT_WINDOW_HEIGHT);
	if (x < 100 || x > win_w - 100) {  //you can use values other than 100 for the screen edges if you like, kind of seems to depend on your mouse sensitivity for what ends up working best
		lastX = win_w / 2;   //centers the last known position, this way there isn't an odd jump with your cam as it resets
		lastY = win_h / 2;
		glutWarpPointer(win_w / 2, win_h / 2);  //centers the cursor
	}
	else if (y < 100 || y > win_h - 100) {
		lastX = win_w / 2;
		lastY = win_h / 2;
		glutWarpPointer(win_w / 2, win_h / 2);
	}
	//std::cout << "cameraFront" << glm::to_string(cameraFront) << std::endl;
	//std::cout << "Camera pos" << glm::to_string(cameraPos) << std::endl;
}
*/
