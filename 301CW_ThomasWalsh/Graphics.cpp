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
	IrrInclude::device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(WIDTH, HEIGHT), 16, false, false, false, 0);
	IrrInclude::driver = IrrInclude::device->getVideoDriver();
	IrrInclude::sceneManager = IrrInclude::device->getSceneManager();
	std::cout << "Graphics Created" << std::endl;
}

Graphics::~Graphics()
{
	IrrInclude::device->drop();
	std::cout << "Graphics has deleted" << std::endl;
}

void Graphics::addEvent(Event e)
{
	events.push_back(e);
}

core::vector3df convertToCore(glm::vec3 change) {
	
	core::vector3df changed =  core::vector3df(change.x,change.y, change.z);

	return changed;
}

void Graphics::Draw() {
	for (int i = 0; i < GameEngine::entities.size(); i++) {
		if (GameEngine::entities[i]->getCurrentMesh() != nullptr ) {
			//GameEngine::entities[i]->getCurrentMesh()->animatedSceneNode = IrrInclude::device->getSceneManager()->addAnimatedMeshSceneNode(GameEngine::entities[i]->getCurrentMesh()->model);

			//GameEngine::entities[i]->getCurrentMesh()->animatedSceneNode->setPosition(convertToCore(glm::vec3(0,1000,0)));
			GameEngine::entities[i]->getCurrentMesh()->animatedSceneNode->setPosition(convertToCore(GameEngine::entities[i]->position));
		}
		else if (GameEngine::entities[i]->type == EntityEnum(1)) {
			IrrInclude::camera->setPosition(convertToCore(GameEngine::entities[i]->position));
			IrrInclude::camera->setTarget(convertToCore(GameEngine::entities[i]->getTargetPos()));
		}
	}


}

void Graphics::init()
{
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
	IrrInclude::camera->setTarget(core::vector3df(0,0,1));

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
	
	Entity* cannon = new moveEntity(glm::vec3(0, 100, 0), "cannon");
	GameEngine::entities.push_back(cannon);
	
	Entity* cannon1 = new moveEntity(glm::vec3(0, -100, 0), "cannon");
	GameEngine::entities.push_back(cannon1);

	Entity* cannon2 = new moveEntity(glm::vec3(0, -200, 0), "cannon");
	GameEngine::entities.push_back(cannon2);

	Entity* test = new moveEntity(glm::vec3(0, 0, 0), "Test");
	GameEngine::entities.push_back(test);

	int count = 0;
	for (int i = 0; i < GameEngine::entities.size(); i++) {
		if (GameEngine::entities[i]->getCurrentMesh() != nullptr) {
			GameEngine::entities[i]->getCurrentMesh()->animatedSceneNode = IrrInclude::device->getSceneManager()->addAnimatedMeshSceneNode(GameEngine::entities[i]->getCurrentMesh()->model);
			//GameEngine::entities[i]->getCurrentMesh()->animatedSceneNode->setPosition(convertToCore(GameEngine::entities[i]->position));
			count++;
			if (count == 2) {
				GameEngine::entities[i]->getCurrentMesh()->animatedSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);
			}
			else if (count == 1) {
				GameEngine::entities[i]->getCurrentMesh()->animatedSceneNode->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
				GameEngine::entities[i]->getCurrentMesh()->animatedSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);
				GameEngine::entities[i]->getCurrentMesh()->animatedSceneNode->setDebugDataVisible(true);
			}
		}
	}
}

void Graphics::update()
{
	Draw();
	if (IrrInclude::device->run()){
		IrrInclude::driver->beginScene(true, true, video::SColor(0, 0, 0, 200));
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
					std::cout << "Seen event graphics" << std::endl; 

					//functions[int(GameEngine::eventQueue[i]->functPoint)](GameEngine::eventQueue[i], GameEngine::eventQueue[i]->eventInfo.dir, GameEngine::eventQueue[i]->eventInfo.speed);
					GameEngine::eventQueue[i]->mySubs.erase(GameEngine::eventQueue[i]->mySubs.begin() + j);
				}
			}
		}
	}
}
