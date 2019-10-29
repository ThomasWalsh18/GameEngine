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
	std::cout << "Graphics has deleted" << std::endl;
}

void Graphics::addEvent(Event e)
{
	events.push_back(e);
}
glm::vec3 convertToVec3(core::vector3df change) {
	
	glm::vec3 changed = glm::vec3(change.X,change.Y, change.Z);

	return changed;
}
core::vector3df convertToCore(glm::vec3 change) {
	
	core::vector3df changed =  core::vector3df(change.x,change.y, change.z);

	return changed;
}
void updatePos(Entity* entity, int direction, float speed) {
	// eventrually I will have a graphics system that uses vec3's so that 
	//Physics can jnust simply update the vec3 to the new one and graphics can draw it 

	if (direction == -1) {
		entity->position += convertToVec3(core::vector3df(0,0, speed));
		CameraEntitiy* camEntity = static_cast<CameraEntitiy*>(GameEngine::entities[0]);
		camEntity->targetPos += convertToVec3(core::vector3df(0, 0, speed));
		
	}
	else if (direction == 1) {
		entity->position += convertToVec3(core::vector3df(0, 0, -speed));
		CameraEntitiy* camEntity = static_cast<CameraEntitiy*>(GameEngine::entities[0]);
		camEntity->targetPos += convertToVec3(core::vector3df(0, 0, -speed));
	}
	else if (direction == 2) {
		entity->position += convertToVec3(core::vector3df(-speed, 0, 0));
		CameraEntitiy* camEntity = static_cast<CameraEntitiy*>(GameEngine::entities[0]);
		camEntity->targetPos += convertToVec3(core::vector3df(-speed, 0, 0));
	}
	else if (direction == -2) {
		entity->position += convertToVec3(core::vector3df(speed, 0, 0));
		CameraEntitiy* camEntity = static_cast<CameraEntitiy*>(GameEngine::entities[0]);
		camEntity->targetPos += convertToVec3(core::vector3df(speed, 0, 0));
	}
	else if (direction == -3) {
		entity->position += convertToVec3(core::vector3df(0, speed, 0));
		CameraEntitiy* camEntity = static_cast<CameraEntitiy*>(GameEngine::entities[0]);
		camEntity->targetPos += convertToVec3(core::vector3df(0, speed, 0));
	}
	else if (direction == 3) {
		entity->position += convertToVec3(core::vector3df(0, -speed, 0));
		CameraEntitiy* camEntity = static_cast<CameraEntitiy*>(GameEngine::entities[0]);
		camEntity->targetPos += convertToVec3(core::vector3df(0, -speed, 0));
	}
	
}

void Graphics::Draw(Entity* entity) {
	CameraEntitiy* camEntity = static_cast<CameraEntitiy*>(entity);
	if (camEntity)
	{
		camera->setPosition(convertToCore(camEntity->position));
		camera->setTarget(convertToCore(camEntity->targetPos));
	}

}


void Graphics::init()
{
	this->device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(WIDTH, HEIGHT), 16, false, false, false, 0);

	this->driver = device->getVideoDriver();
	this->sceneManager = device->getSceneManager();

	this->device->getFileSystem()->addFileArchive("./include/irrlicht-1.8.4/media/map-20kdm2.pk3");
	//this->device->getFileSystem()->addFileArchive("./include/irrlicht-1.8.4/media/ra3slob2.pk3");
	this->mesh = sceneManager->getMesh("20kdm2.bsp");
	//this->mesh = sceneManager->getMesh("ra3slob2.bsp");
	this->node = 0;

	if (this->mesh) {
		this->node = sceneManager->addOctreeSceneNode(this->mesh->getMesh(0), 0, -1, 1024);
	}

	if (this->node) {
		this->node->setPosition(core::vector3df(-1300, -144, -1249));
		//this->node->setPosition(core::vector3df(0, 0, 0));
	}


	camera = sceneManager->addCameraSceneNode();
	camera->setPosition(core::vector3df(0,0,0));
	camera->setTarget(core::vector3df(0,0,1));
	Entity* Camera = new Entity(glm::vec3(0,0,0));
	GameEngine::entities.push_back(Camera);
	CameraEntitiy* camEntity = static_cast<CameraEntitiy*>(GameEngine::entities[0]);
	if (camEntity)
	{
		camEntity->targetPos = glm::vec3(camEntity->position.x, camEntity->position.y, camEntity->position.z + 1);
	}

	device->getCursorControl()->setVisible(false);
	
	// funct point
	void(*updateEnity)(Entity* , int , float ) = updatePos;
	functions[0] = updatePos;

	//Find a way to speerate the hardcoding from entities
}

void Graphics::update()
{
	Draw(GameEngine::entities[0]);
	if (device->run()){
		driver->beginScene(true, true, video::SColor(255, 200, 200, 200));
		sceneManager->drawAll();
		driver->endScene();

		int fps = driver->getFPS();

		if (this->lastFPS != fps)
		{
			core::stringw str = L"Irrlicht Engine - Quake 3 Map [";
			str += driver->getName();
			str += "] FPS:";
			str += fps;

			device->setWindowCaption(str.c_str());
			this->lastFPS = fps;
		}
	}
	
	if (GameEngine::eventQueue.size() != 0) { // if event Q is populated
		for (int i = 0; i < GameEngine::eventQueue.size(); i++) {	// for each event, then for each sub system in each event
			for (int j = 0; j < GameEngine::eventQueue[i]->mySubs.size(); j++) {
				if (GameEngine::eventQueue[i]->mySubs[j] == SubSystemEnum(2)) { // check to see if it need the current subsystem
					std::cout << "Seen event graphics" << std::endl; 
					// HARD CODED VALUES ALEART !!!										below
					functions[int(GameEngine::eventQueue[i]->functPoint)](GameEngine::entities[0], GameEngine::eventQueue[i]->eventInfo.dir, GameEngine::eventQueue[i]->eventInfo.speed);
					GameEngine::eventQueue[i]->mySubs.erase(GameEngine::eventQueue[i]->mySubs.begin() + j);
					//do the actual stuff now like checking to see what it is for example is it a move event
					//if event enum type == 0 move. Dont know how to do the different speeds and or directions without load of different events
				}
			}
		}
	}
}
