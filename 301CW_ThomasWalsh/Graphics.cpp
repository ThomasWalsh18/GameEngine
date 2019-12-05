#include "Graphics.h"
/*
	- Graphics
		The player
		other entities
		terrain
		skybox
*/
HWND Graphics::hWnd;

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

Graphics::Graphics()
{
	WIDTH = GameEngine::width;
	HEIGHT = GameEngine::height;
	title = GameEngine::title;

	HINSTANCE hInstance = 0;
	// create dialog

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
	wcex.hbrBackground = NULL;//(HBRUSH)(COLOR_WINDOW);
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


core::vector3df convertToCore(glm::vec3 change) {
	
	core::vector3df changed =  core::vector3df(change.x,change.y, change.z);

	return changed;
}
glm::vec3 convertFromBullet(btVector3 change) {

	glm::vec3 changed =  glm::vec3(change.x(),change.y(), change.z());

	return changed;
}

bool Graphics::firstMove = true;
int Graphics::lastX = -1;
int Graphics::lastY = -1;;
float Graphics::pitch = 0.0f;
float Graphics::yaw = 90.0f;
float Graphics::sensitivity = 0.3f;
glm::vec3 Graphics::cameraFront = glm::vec3(0,0,-1);

void Graphics::Draw() {
	int main = 0;
	for (int i = 0; i < GameEngine::entities.size(); i++) {
		if (GameEngine::entities[i]->getCurrentMesh() != nullptr ) {
			if (GameEngine::entities[i]->type == EntityEnum(0)) {
				main = i;
			}
			GameEngine::entities[i]->GetSceneNode()->setPosition(convertToCore(convertFromBullet(GameEngine::entities[i]->getRigidBody()->getWorldTransform().getOrigin())));
		}
		else if (GameEngine::entities[i]->type == EntityEnum(1)) {
			IrrInclude::camera->setPosition(convertToCore(glm::vec3(10.0f, 175.0f, -30.0f) + convertFromBullet(GameEngine::entities[main]->getRigidBody()->getWorldTransform().getOrigin())));
			IrrInclude::camera->setTarget(convertToCore(Graphics::cameraFront + (glm::vec3(10.0f, 175.0f, -30.0f) + convertFromBullet(GameEngine::entities[main]->getRigidBody()->getWorldTransform().getOrigin()))));
		}
		else if (GameEngine::entities[i]->type == EntityEnum(4)) {
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
	float yoffset = Graphics::lastY - e->eventInfo.y; // reversed since y-coordinates go from bottom to top
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

	// How Do I get these without a reference to a specific object
	ShowCursor(TRUE);
	RECT size;
	GetWindowRect(Graphics::hWnd, &size);
	int win_w = size.right;
	int win_h = size.bottom;

	if (e->eventInfo.x < 100 || e->eventInfo.x > win_w - 100) {  //you can use values other than 100 for the screen edges if you like, depends on your mouse sensitivity for what ends up working best
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
	//GameEngine::entities[1]->GetSceneNode()->setRotation(core::vector3df(0, Graphics::cameraFront.y,0));
}

void level(Event* e) {

	Entity* mainChar = nullptr;
	for (int i = 0; i < GameEngine::entities.size(); i++) {
		if (int(GameEngine::entities[i]->type) == 0) {
			mainChar = GameEngine::entities[i];
			break;
		}
	}
	IrrInclude::camera = IrrInclude::sceneManager->addCameraSceneNode();
	if (mainChar != nullptr) {
		IrrInclude::camera->setPosition(convertToCore(mainChar->position));
	}
	else {
		std::cout << "No main Char in elementList.lua" << std::endl;
	}
	IrrInclude::camera->setTarget(convertToCore(Graphics::cameraFront));
	IrrInclude::camera->setFarValue(irr::f32(6000.0f));

	Entity* Camera = new CameraEntitiy(mainChar->position + glm::vec3(10.0f, 175.0f, -30.0f), EntityEnum(1));
	//Entity* Camera = new CameraEntitiy(Giant->position + glm::vec3(10.0f, 175.0f, -30.0f), EntityEnum(1));
	GameEngine::entities.push_back(Camera);

	for (int i = 0; i < GameEngine::entities.size(); i++) {
		if (int(GameEngine::entities[i]->type) != 1) {
			if (int(GameEngine::entities[i]->type) == 4) {
				scene::IMeshSceneNode* box = IrrInclude::sceneManager->addCubeSceneNode(GameEngine::entities[i]->getSize(), 0, -1, convertToCore(GameEngine::entities[i]->position), convertToCore(GameEngine::entities[i]->getRotation()), convertToCore(GameEngine::entities[i]->getScale()));
				GameEngine::entities[i]->SetSimpleSceneNode(box);
				if (GameEngine::entities[i]->getTexture() != "!") {
					std::string texturePath = "./media/" + GameEngine::entities[i]->getTexture();
					GameEngine::entities[i]->GetSimpleSceneNode()->setMaterialTexture(0, IrrInclude::driver->getTexture(texturePath.c_str()));
				}
			}
			else {
				if (GameEngine::entities[i]->getCurrentMesh() != nullptr) {
					GameEngine::entities[i]->SetSceneNode(GameEngine::entities[i]->getCurrentMesh()->model);
				}
				if (GameEngine::entities[i]->getTexture() != "!") {
					std::string texturePath = "./media/" + GameEngine::entities[i]->getTexture();
					GameEngine::entities[i]->GetSceneNode()->setMaterialTexture(0, IrrInclude::driver->getTexture(texturePath.c_str()));
				}
			}
		}
	}
}

void Graphics::init()
{
	font = IrrInclude::device->getGUIEnvironment()->getBuiltInFont();

	void(*mouse)(Event*) = mouseMove;
	functions[1] = mouseMove;
	void(*close)(Event*) = Close;
	functions[2] = Close;

	void(*NewLevel)(Event*) = level;
	functions[5] = level;
	/*
	IrrInclude::device->getFileSystem()->addFileArchive("./include/irrlicht-1.8.4/media/map-20kdm2.pk3");
	IrrInclude::mesh = IrrInclude::sceneManager->getMesh("20kdm2.bsp");
	IrrInclude::node = 0;

	if (IrrInclude::mesh) {
		IrrInclude::node = IrrInclude::sceneManager->addOctreeSceneNode(IrrInclude::mesh->getMesh(0), 0, -1, 1024);
	}
	if (IrrInclude::node) {
		IrrInclude::node->setPosition(core::vector3df(-1300, -144, -1249));
	}
	*/

	// could be data driven
	IrrInclude::device->getCursorControl()->setVisible(false);
	IrrInclude::sceneManager->addSkyBoxSceneNode(
		IrrInclude::driver->getTexture("./media/irrlicht2_up.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_dn.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_lf.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_rt.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_ft.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_bk.jpg"));
	
	scene::ILightSceneNode* light1 = IrrInclude::sceneManager->addLightSceneNode(0, core::vector3df(20, 1000, -200), video::SColorf(1.0f, 1.0f, 1.0f, 1.0f), 6000.0f);
	
	Event* caller = nullptr;
	level(caller);
}

void Graphics::update()
{
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

	if (IrrInclude::device->run()){
		IrrInclude::driver->beginScene(true, true, 0, videodata);
		//IrrInclude::driver->beginScene(true, true, video::SColor(0, 0, 0, 200));
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

