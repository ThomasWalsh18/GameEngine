#include "Graphics.h"
/*
	- Graphics
		The tank itself
		other tanks
		terrain
		sky
*/

Graphics::Graphics()
{

	std::cout << "Graphics Created" << std::endl;
}

Graphics::~Graphics()
{
	this->device->drop();
	//Quit SDL subsystems
	/*
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();
	*/
	std::cout << "Graphics has deleted" << std::endl;
}

void Graphics::addEvent(Event e)
{
	events.push_back(e);
}

void updatePos(Entity* entity, int direction, float speed) {
	// eventrually I will have a  graphics system that uses vec3's so that 
	//Physics can jnust simply update the vec3 to the new one and graphics can draw it 
	if (direction == -1) {
		entity->position.y = entity->position.y + speed;
	}
	else if (direction == 1) {
		entity->position.y = entity->position.y - speed;
	}
	else if (direction == 2) {
		entity->position.x = entity->position.x - speed;
	}
	else if (direction == -2) {
		entity->position.x = entity->position.x + speed;
	}

}

void Graphics::Draw(Entity* entity) {
	//rect.x = entity->position.x;
	//rect.y = entity->position.y;
}


void Graphics::init()
{
	this->device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(WIDTH, HEIGHT), 16, false, false, false, 0);

	this->driver = device->getVideoDriver();
	this->sceneManager = device->getSceneManager();
	this->guienv = device->getGUIEnvironment();

	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!", core::rect<s32>(10, 10, 260, 22), true);

	this->device->getFileSystem()->addFileArchive("./include/irrlicht-1.8.4/media/map-20kdm2.pk3");
	this->mesh = sceneManager->getMesh("20kdm2.bsp");
	this->node = 0;

	if (this->mesh) {
		this->node = sceneManager->addOctreeSceneNode(this->mesh->getMesh(0), 0, -1, 1024);
	}

	if (this->node) {
		this->node->setPosition(core::vector3df(-1300, -144, -1249));
	}
	sceneManager->addCameraSceneNodeFPS();
	//device->getCursorControl()->setVisible(false);

	/*
	this->mesh = sceneManager->getMesh("./include/irrlicht-1.8.4/media/sydney.md2");
	if (!this->mesh)
	{
		this->device->drop();
		std::cout << "NO MODEL" << std::endl;
	}
	this->node = sceneManager->addAnimatedMeshSceneNode(this->mesh);

	if (this->node)
	{
		this->node->setMaterialFlag(video::EMF_LIGHTING, false);
		this->node->setMD2Animation(scene::EMAT_STAND);
		this->node->setMaterialTexture(0, driver->getTexture("./include/irrlicht-1.8.4/media/sydney.bmp"));
	}
	this->sceneManager->addCameraSceneNode(0, core::vector3df(0, 30, -40), core::vector3df(0, 5, 0));
	*/
	/*
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Error initilsing. SDL Error: %s \n", SDL_GetError());
	}
	else {
		window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		surface = SDL_GetWindowSurface(window);
		if (window == NULL)
		{
			printf("could not create window: %s\n", SDL_GetError());
		}
		else {
	
			SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));
			std::cout << "Graphics Init" << std::endl;
		}
		
	}
	*/
	void(*updateEnity)(Entity * , int , float ) = updatePos;
	functions[0] = updatePos;

	//Find a way to speerate the hardcoding from entities
	/*
	rect.w = 190;
	rect.h = 198;
	rect.x = 600;
	rect.y = 2;

	Entity* Rect = new RectEntity(glm::vec3(rect.x, rect.y, 0.0f), rect.h, rect.w);
	GameEngine::entities.push_back(Rect);
	*/
}

void Graphics::update()
{
	if (device->run()){
	
		driver->beginScene(true, true, video::SColor(255, 200, 200, 200));
		sceneManager->drawAll();
		driver->endScene();

		int fps = driver->getFPS();

		if (this->lastFPS != fps)
		{
			core::stringw str = L"Irrlicht Engine - Quake 3 Map example [";
			str += driver->getName();
			str += "] FPS:";
			str += fps;

			device->setWindowCaption(str.c_str());
			this->lastFPS = fps;
		}

	}
	/*
	Draw(GameEngine::entities[0]);
	SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
	*/


	if (GameEngine::eventQueue.size() != 0) { // if event Q is populated
		for (int i = 0; i < GameEngine::eventQueue.size(); i++) {	// for each event, then for each sub system in each event
			for (int j = 0; j < GameEngine::eventQueue[i]->mySubs.size(); j++) {
				if (GameEngine::eventQueue[i]->mySubs[j] == SubSystemEnum(2)) { // check to see if it need the current subsystem
					std::cout << "Seen event graphics" << std::endl; 

					functions[int(GameEngine::eventQueue[i]->functPoint)](GameEngine::entities[0], GameEngine::eventQueue[i]->eventInfo.dir, GameEngine::eventQueue[i]->eventInfo.speed);
					GameEngine::eventQueue[i]->mySubs.erase(GameEngine::eventQueue[i]->mySubs.begin() + j);
					//do the actual stuff now like checking to see what it is for example is it a move event
					//if event enum type == 0 move. Dont know how to do the different speeds and or directions without load of different events
				}
			}
		}
	}
}
