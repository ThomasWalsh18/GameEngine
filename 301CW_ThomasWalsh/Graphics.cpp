#include "Graphics.h"
/*
	- Graphics
		Irrlicht engine 
		Windows window
*/

HWND Graphics::hWnd;
Entity* Graphics::mainChar = nullptr;
//A default windows function a windodw needs
static LRESULT CALLBACK CustomWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_COMMAND:
		{
			HWND hwndCtl = (HWND)lParam;
			int code = HIWORD(wParam);
		}
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
// On constuction
Graphics::Graphics()
{
	/*
	These are based from a LUA Script, this is one way I could improve my GameEngine
	I could move the LUA script that is specific to graphics from the LUA Subsystem 
	Which then passes the information over to game engine and then over to Graphics,
	Over to the graphics constructor
	*/
	WIDTH = GameEngine::width;
	HEIGHT = GameEngine::height;
	title = GameEngine::title;

	HINSTANCE hInstance = 0;
	/*
	Create dialog between a irrlicht renderer and a windows window, 
	I use a windows window so that I can detect mouse movement relevant to the mouse pos
	On the current selected window
	*/

	const char* Win32ClassName = "CIrrlichtWindowsTestDialog";

	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)CustomWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = DLGWINDOWEXTRA;
	wcex.hInstance = hInstance;
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = NULL;
	wcex.lpszMenuName = 0;
	wcex.lpszClassName = Win32ClassName;
	wcex.hIconSm = 0;

	RegisterClassEx(&wcex);

	DWORD style = WS_CAPTION | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX | WS_SYSMENU;

	hWnd = CreateWindow(Win32ClassName, title.c_str(), style, 100, 100, WIDTH, HEIGHT, NULL, NULL, hInstance, NULL);

	HWND hIrrlichtWindow =  CreateWindow("BUTTON", "", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, 0, 0, WIDTH, HEIGHT, hWnd, NULL, hInstance, NULL);
	videodata = video::SExposedVideoData(hIrrlichtWindow);
	
	SIrrlichtCreationParameters param;
	param.DriverType = video::EDT_DIRECT3D9;
	param.WindowId = reinterpret_cast<void*>(hIrrlichtWindow);
	IrrInclude::device = createDeviceEx(param);
	
	//IrrInclude::device = createDevice(video::EDT_DIRECT3D9, core::dimension2d<u32>(WIDTH, HEIGHT), 16, false, false, false, 0);
	IrrInclude::driver = IrrInclude::device->getVideoDriver();
	IrrInclude::sceneManager = IrrInclude::device->getSceneManager();


	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	
	std::cout << "Graphics Created" << std::endl;
}

Graphics::~Graphics()
{
	IrrInclude::device->drop();
	std::cout << "Graphics has deleted" << std::endl;
}

//Its these sort of Covnersions I could include in my Maths libary

core::vector3df convertToCore(glm::vec3 change) {
	
	core::vector3df changed =  core::vector3df(change.x,change.y, change.z);

	return changed;
}
glm::vec3 convertFromBullet(btVector3 change) {

	glm::vec3 changed =  glm::vec3(change.x(),change.y(), change.z());

	return changed;
}
//Static variables for my mouse move code,
//This is because the mouse move code doesnt use the Graphics Namespace
bool Graphics::firstMove = true;
int Graphics::lastX = -1;
int Graphics::lastY = -1;;
float Graphics::pitch = 0.0f;
float Graphics::yaw = 90.0f;
float Graphics::sensitivity = 0.3f;
glm::vec3 Graphics::cameraFront = glm::vec3(0,0,-1);

void Graphics::Draw() {
	/*
	To draw I look through each entity and check what type they are and if they have a mesh already
	I also then check to see which enitity the main character is, this way the camera is always on the main char
	*/
	int main = 0;
	for (int i = 0; i < GameEngine::entities.size(); i++) {
		if (GameEngine::entities[i]->getCurrentMesh() != nullptr ) {
			if (GameEngine::entities[i]->type == EntityEnum(0)) {
				main = i;
			}
			/*
			To move a charcter I have to get the Irrlicht scene node, then set its postion to the matching entities rigid body's position
			Then I have to convert from a btVector3 (bullet), to a Glm::vec3, then to a irrlicht vector3df
			*/
			GameEngine::entities[i]->GetSceneNode()->setPosition(convertToCore(convertFromBullet(GameEngine::entities[i]->getRigidBody()->getWorldTransform().getOrigin())));
		}
		else if (GameEngine::entities[i]->type == EntityEnum(1)) {
			/*
			Then if the entity is the camera, as this entity will not have a Mesh
			I need to update the cameras postion and target to get it looking in the right direction
			I Could have used a fps camers from Irrlicht, however it uses its own event system
			*/
			IrrInclude::camera->setPosition(convertToCore(glm::vec3(10.0f, 175.0f, -30.0f) + convertFromBullet(GameEngine::entities[main]->getRigidBody()->getWorldTransform().getOrigin())));
			IrrInclude::camera->setTarget(convertToCore(Graphics::cameraFront + (glm::vec3(10.0f, 175.0f, -30.0f) + convertFromBullet(GameEngine::entities[main]->getRigidBody()->getWorldTransform().getOrigin()))));
		}
		else if (GameEngine::entities[i]->type == EntityEnum(4)) {
			/*
			This is the draw code for the basic entities, these will also have no mesh and just updates the position from a different getter
			*/
			GameEngine::entities[i]->GetSimpleSceneNode()->setPosition(convertToCore(convertFromBullet(GameEngine::entities[i]->getRigidBody()->getWorldTransform().getOrigin())));
		}
	}
}

void Close(Event* e) {
	IrrInclude::device->closeDevice();
	CloseWindow(Graphics::hWnd);
}
void mouseMove(Event* e)
{
	if (Graphics::firstMove)
	{
		Graphics::lastX = e->eventInfo.x;
		Graphics::lastY = e->eventInfo.y;
		Graphics::firstMove = false;
	}

	float xoffset = e->eventInfo.x - Graphics::lastX;
	float yoffset = Graphics::lastY - e->eventInfo.y; 
	Graphics::lastX = e->eventInfo.x;
	Graphics::lastY = e->eventInfo.y;

	xoffset *= Graphics::sensitivity;
	yoffset *= Graphics::sensitivity;

	Graphics::yaw += xoffset;
	Graphics::pitch += yoffset;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (Graphics::pitch > 89.0f) {
		Graphics::pitch = 89.0f;
	}
	if (Graphics::pitch < -89.0f) {
		Graphics::pitch = -89.0f;
	}

	glm::vec3 front;
	front.x = cos(glm::radians(Graphics::yaw)) * cos(glm::radians(Graphics::pitch));
	front.y = sin(glm::radians(Graphics::pitch));
	front.z = -sin(glm::radians(Graphics::yaw)) * cos(glm::radians(Graphics::pitch));
	Graphics::cameraFront = glm::normalize(front);
	Graphics::cameraFront.x = Graphics::cameraFront.x;
	Graphics::cameraFront.y = Graphics::cameraFront.y;
	
	//std::cout << Graphics::cameraFront.x << std::endl;
	//std::cout << Graphics::cameraFront.y << std::endl;
	//std::cout << Graphics::cameraFront.z << std::endl;

	//force mouse to stay inside the window
	RECT size;
	GetWindowRect(Graphics::hWnd, &size);
	int win_w = size.right;
	int win_h = size.bottom;

	if (e->eventInfo.x < 100 || e->eventInfo.x > win_w - 100) {
		Graphics::lastX = win_w / 2;   //centers the last known position, this way there isn't an odd jump with your cam as it resets
		Graphics::lastY = win_h / 2;
		SetCursorPos(win_w / 2, win_h / 2);
	}
	else if (e->eventInfo.y < 100 || e->eventInfo.y > win_h - 100) {
		Graphics::lastX = win_w / 2;
		Graphics::lastY = win_h / 2;
		SetCursorPos(win_w / 2, win_h / 2);
	}
	Event* upDatePhys = new Event(EventTypeEnum(4));
	upDatePhys->eventInfo.Header = Graphics::cameraFront;
	GameEngine::eventQueue.push_back(upDatePhys);
	
}

void level(Event* e) {
	/*
	This code loads in a level from the current game enginge entities
	First check for the main character
	*/
	for (int i = 0; i < GameEngine::entities.size(); i++) {
		if (int(GameEngine::entities[i]->type) == 0) {
			Graphics::mainChar = GameEngine::entities[i];
			break;
		}
	}
	/*
	Now I can create a camera around the main characters position, and set up some default values for it
	*/
	IrrInclude::camera = IrrInclude::sceneManager->addCameraSceneNode();
	if (Graphics::mainChar != nullptr) {
		IrrInclude::camera->setPosition(convertToCore(Graphics::mainChar->position));
	}
	else {
		std::cout << "No main Char in elementList.lua" << std::endl;
	}
	IrrInclude::camera->setTarget(convertToCore(Graphics::cameraFront));
	IrrInclude::camera->setFarValue(irr::f32(6000.0f));
	Entity* Camera = new CameraEntitiy(Graphics::mainChar->position + glm::vec3(10.0f, 175.0f, -30.0f), EntityEnum(1));
	GameEngine::entities.push_back(Camera);

	/*
	Now I loop thorugh each entity doing nothing for the camera, and setting the textures, meshes and animatons for the releaive entites
	*/

	for (int i = 0; i < GameEngine::entities.size(); i++) {
		if (int(GameEngine::entities[i]->type) != 1) { // if its not the camera
			if (int(GameEngine::entities[i]->type) == 4) { // if it is the basic box
				scene::IMeshSceneNode* box = IrrInclude::sceneManager->addCubeSceneNode(GameEngine::entities[i]->getSize(), 0, -1, convertToCore(GameEngine::entities[i]->position), convertToCore(GameEngine::entities[i]->getRotation()), convertToCore(GameEngine::entities[i]->getScale()));
				GameEngine::entities[i]->SetSimpleSceneNode(box);
				if (GameEngine::entities[i]->getTexture() != "!") {
					std::string texturePath = "./media/" + GameEngine::entities[i]->getTexture();
					GameEngine::entities[i]->GetSimpleSceneNode()->setMaterialTexture(0, IrrInclude::driver->getTexture(texturePath.c_str()));
				}
			}
			else { // if it has a mesh
				if (GameEngine::entities[i]->getCurrentMesh() != nullptr) {
					GameEngine::entities[i]->SetSceneNode(GameEngine::entities[i]->getCurrentMesh()->model);
				}
				if (GameEngine::entities[i]->getCurrentMesh()->path == "./media/IronGiantA.X") {
					GameEngine::entities[i]->GetSceneNode()->setFrameLoop(0, 0);
				}
				if (GameEngine::entities[i]->getTexture() != "!") {
					std::string texturePath = "./media/" + GameEngine::entities[i]->getTexture();
					GameEngine::entities[i]->GetSceneNode()->setMaterialTexture(0, IrrInclude::driver->getTexture(texturePath.c_str()));
				}
			}
		}
	}
}

void animation(Event* e) {
	/*
	Basic animation controller,
		This method is propably really bad way of doing it, as the animation will constantly be set to frame 0 when moving,
		then when not moving the animation plays
	*/
	if (Graphics::mainChar->getCurrentMesh()->path =="./media/IronGiantA.X") {
		Graphics::mainChar->GetSceneNode()->setFrameLoop(0, 45);
	}
}

void Graphics::init()
{
	/*
	To start the init function I create a font for my fps counter
	And set up each of the different function pointers I utilise
	And make sure the mouse cannot be seen
	*/
	font = IrrInclude::device->getGUIEnvironment()->getBuiltInFont();

	void(*activeAnim)(Event*) = animation;
	functions[0] = animation;

	void(*mouse)(Event*) = mouseMove;
	functions[1] = mouseMove;

	void(*close)(Event*) = Close;
	functions[2] = Close;

	void(*NewLevel)(Event*) = level;
	functions[5] = level;

	IrrInclude::device->getCursorControl()->setVisible(false);
	/*
	Another Area for improvement as my sky box textures are not dependent on a lua file 
	Adding in a data driven skybox could allow for very different looking levels
	*/
	IrrInclude::sceneManager->addSkyBoxSceneNode(
		IrrInclude::driver->getTexture("./media/irrlicht2_up.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_dn.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_lf.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_rt.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_ft.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_bk.jpg"));
	/*
	Light 1 is a basic light that acts as the sun in my game
	*/
	scene::ILightSceneNode* light1 = IrrInclude::sceneManager->addLightSceneNode(0, core::vector3df(20, 1000, -200), video::SColorf(1.0f, 1.0f, 1.0f, 1.0f), 6000.0f);
	
	/*
	To call the level creator I need an event, this is a empty event to allow the call to take place
	*/
	Event* caller = nullptr;
	level(caller);
}

void Graphics::update()
{
	/*
	Event Queue as explained in game engine
	*/
	if (GameEngine::eventQueue.size() != 0) { // if event Q is populated
		for (int i = 0; i < GameEngine::eventQueue.size(); i++) {	// for each event, then for each sub system in each event
			for (int j = 0; j < GameEngine::eventQueue[i]->mySubs.size(); j++) {
				if (GameEngine::eventQueue[i]->mySubs[j] == SubSystemEnum(2)) { // check to see if it need the current subsystem
					functions[int(GameEngine::eventQueue[i]->functPoint)](GameEngine::eventQueue[i]);
					GameEngine::eventQueue[i]->mySubs.erase(GameEngine::eventQueue[i]->mySubs.begin() + j);
				}
			}
		}
	}

	/*
	For irrlicht I have to do the draw code 
	and set what my fps counter will say
	*/
	if (IrrInclude::device->run()){
		IrrInclude::driver->beginScene(true, true, 0, videodata);
		Draw();
		IrrInclude::sceneManager->drawAll();
		
		font->draw(text.c_str(),
			core::rect<s32>(130, 10, 300, 50),
			video::SColor(255, 255, 255, 255));

		IrrInclude::driver->endScene();
		
		int fps = IrrInclude::driver->getFPS();

		if (this->lastFPS != fps)
		{
			text = L"Irrlicht Engine - Driver:[";
			text += IrrInclude::driver->getName();
			text += "] FPS:";
			text += fps;

			this->lastFPS = fps;
		}
		
	}
	

}

