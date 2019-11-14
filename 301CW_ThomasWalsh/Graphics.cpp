#include "Graphics.h"
/*
	- Graphics
		The tank itself
		other tanks
		terrain
		sky
*/


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

	hWnd = CreateWindow(Win32ClassName, "301__Game Engine", style, 100, 100, WIDTH, HEIGHT, NULL, NULL, hInstance, NULL);

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

bool Graphics::firstMove = true;
int Graphics::lastX = -1;
int Graphics::lastY = -1;;
float Graphics::pitch = 0.0f;
float Graphics::yaw = 90.0f;
float Graphics::sensitivity = 0.3f;
glm::vec3 Graphics::cameraFront = glm::vec3(0,0,1);

void Graphics::Draw() {
	for (int i = 0; i < GameEngine::entities.size(); i++) {
		if (GameEngine::entities[i]->getCurrentMesh() != nullptr ) {
			GameEngine::entities[i]->GetSceneNode()->setPosition(convertToCore(GameEngine::entities[i]->position));
		}
		else if (GameEngine::entities[i]->type == EntityEnum(1)) {
			IrrInclude::camera->setPosition(convertToCore(GameEngine::entities[i]->position));
			IrrInclude::camera->setTarget(convertToCore(Graphics::cameraFront + GameEngine::entities[i]->position));
		}
	}
}

int Graphics::GetWidth()
{
	return this->WIDTH;
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
	front.z = sin(glm::radians(Graphics::yaw)) * cos(glm::radians(Graphics::pitch));
	Graphics::cameraFront = glm::normalize(front);
	Graphics::cameraFront.x = -Graphics::cameraFront.x;
	Graphics::cameraFront.y = Graphics::cameraFront.y;
	
	//force mouse to stay inside the window

	// How Do I get these without a reference to a specific object
	
	int win_w = 1600;
	int win_h = 900;
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
	
}


void Graphics::init()
{
	void(*mouse)(Event*) = mouseMove;
	functions[1] = mouseMove;

	IrrInclude::device->getFileSystem()->addFileArchive("./include/irrlicht-1.8.4/media/map-20kdm2.pk3");
	IrrInclude::mesh = IrrInclude::sceneManager->getMesh("20kdm2.bsp");
	IrrInclude::node = 0;

	if (IrrInclude::mesh) {
		IrrInclude::node = IrrInclude::sceneManager->addOctreeSceneNode(IrrInclude::mesh->getMesh(0), 0, -1, 1024);
	}
	if (IrrInclude::node) {
		IrrInclude::node->setPosition(core::vector3df(-1300, -144, -1249));
	}


	////////ADDING CUSTOM OBJS/////////
	//scene::IAnimatedMesh* m = device->getSceneManager()->getMesh("./media/cannon.obj");
	//Model = device->getSceneManager()->addAnimatedMeshSceneNode(m);
	//Model->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
	//Model->setMaterialFlag(video::EMF_LIGHTING, false);
	//Model->setDebugDataVisible(true);
	////////ADDING CUSTOM TEXTURES////////// 
	//Model->setMaterialTexture(0, driver->getTexture("./include/irrlicht-1.8.4/media/wall.jpg"));
	
	IrrInclude::camera = IrrInclude::sceneManager->addCameraSceneNode();
	IrrInclude::camera->setPosition(core::vector3df(0,0,0));
	IrrInclude::camera->setTarget(convertToCore(Graphics::cameraFront));

	Entity* Camera = new CameraEntitiy(glm::vec3(0,0,0), EntityEnum(1));
	GameEngine::entities.push_back(Camera);
	for (int i = 0; i < GameEngine::entities.size(); i++) {
		if (GameEngine::entities[i]->type == EntityEnum(1)) {
			GameEngine::entities[i]->setTargetPos(GameEngine::entities[i]->position + glm::vec3(0.0f, 0.0f, 1.0f));
			break;
		}
	}

	IrrInclude::device->getCursorControl()->setVisible(false);
	IrrInclude::sceneManager->addSkyBoxSceneNode(
		IrrInclude::driver->getTexture("./media/irrlicht2_up.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_dn.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_lf.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_rt.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_ft.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_bk.jpg"));
	
	scene::ILightSceneNode* light1 = IrrInclude::sceneManager->addLightSceneNode(0, core::vector3df(20, 1000, -200), video::SColorf(1.0f, 1.0f, 1.0f, 1.0f), 10000.0f);


	Entity* cannon = new moveEntity(glm::vec3(20, 1000, -200), "cannon");
	GameEngine::entities.push_back(cannon);
	
	Entity* cannon1 = new moveEntity(glm::vec3(0, -100, 0), "cannon");
	GameEngine::entities.push_back(cannon1);

	Entity* cannon2 = new moveEntity(glm::vec3(0, -200, 0), "cannon");
	GameEngine::entities.push_back(cannon2);

	Entity* test = new moveEntity(glm::vec3(0, 0, 0), "Test");
	GameEngine::entities.push_back(test);

	Entity* Giant = new moveEntity(glm::vec3(80, -80, 90), "Iron");
	GameEngine::entities.push_back(Giant);


	int count = 0;
	for (int i = 0; i < GameEngine::entities.size(); i++) {
		if (GameEngine::entities[i]->getCurrentMesh() != nullptr) {
			GameEngine::entities[i]->SetSceneNode(GameEngine::entities[i]->getCurrentMesh()->model);
			count++;
			//GameEngine::entities[i]->GetSceneNode()->setMaterialFlag(video::EMF_LIGHTING, false);
			if (count == 1) {
				GameEngine::entities[i]->GetSceneNode()->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
				GameEngine::entities[i]->GetSceneNode()->setMaterialFlag(video::EMF_LIGHTING, false);
				GameEngine::entities[i]->GetSceneNode()->setDebugDataVisible(true);
			}
		}
	}
}

void Graphics::update()
{
	if (IrrInclude::device->run()){
		IrrInclude::driver->beginScene(true, true, 0, videodata);
		//IrrInclude::driver->beginScene(true, true, video::SColor(0, 0, 0, 200));
		Draw();
		IrrInclude::sceneManager->drawAll();
		IrrInclude::driver->endScene();

		int fps = IrrInclude::driver->getFPS();

		if (this->lastFPS != fps)
		{
			core::stringw str = L"Irrlicht Engine - Map[";
			str += IrrInclude::driver->getName();
			str += "] FPS:";
			str += fps;

			IrrInclude::device->setWindowCaption(str.c_str());
			this->lastFPS = fps;
		}
	}
	
	if (GameEngine::eventQueue.size() != 0) { // if event Q is populated
		for (int i = 0; i < GameEngine::eventQueue.size(); i++) {	// for each event, then for each sub system in each event
			for (int j = 0; j < GameEngine::eventQueue[i]->mySubs.size(); j++) {
				if (GameEngine::eventQueue[i]->mySubs[j] == SubSystemEnum(2)) { // check to see if it need the current subsystem
					
					if (GameEngine::eventQueue[i]->functPoint == EventTypeEnum(1)) {
						functions[int(GameEngine::eventQueue[i]->functPoint)](GameEngine::eventQueue[i]);
					}
					GameEngine::eventQueue[i]->mySubs.erase(GameEngine::eventQueue[i]->mySubs.begin() + j);
				}
			}
		}
	}
}

