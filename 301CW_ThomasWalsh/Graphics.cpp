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

void Graphics::Draw(Entity* entity) {
	CameraEntitiy* camEntity = static_cast<CameraEntitiy*>(entity);
	if (camEntity)
	{
		IrrInclude::camera->setPosition(convertToCore(camEntity->position));
		IrrInclude::camera->setTarget(convertToCore(camEntity->targetPos));
	}

}

void Graphics::init()
{
	IrrInclude::device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(WIDTH, HEIGHT), 16, false, false, false, 0);

	IrrInclude::driver = IrrInclude::device->getVideoDriver();
	IrrInclude::sceneManager = IrrInclude::device->getSceneManager();

	IrrInclude::device->getFileSystem()->addFileArchive("./include/irrlicht-1.8.4/media/map-20kdm2.pk3");
	//IrrInclude::device->getFileSystem()->addFileArchive("./include/irrlicht-1.8.4/media/ra3slob2.pk3");
	IrrInclude::mesh = IrrInclude::sceneManager->getMesh("20kdm2.bsp");
	//IrrInclude::mesh = sceneManager->getMesh("ra3slob2.bsp");
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

	Entity* Camera = new Entity(glm::vec3(0,0,0), EntityEnum(1));
	GameEngine::entities.push_back(Camera);
	CameraEntitiy* camEntity = static_cast<CameraEntitiy*>(GameEngine::entities[0]);
	if (camEntity)
	{
		camEntity->targetPos = glm::vec3(camEntity->position.x, camEntity->position.y, camEntity->position.z + 1);
	}

	IrrInclude::device->getCursorControl()->setVisible(false);
	IrrInclude::sceneManager->addSkyBoxSceneNode(
		IrrInclude::driver->getTexture("./media/irrlicht2_up.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_dn.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_lf.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_rt.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_ft.jpg"),
		IrrInclude::driver->getTexture("./media/irrlicht2_bk.jpg"));
}

void Graphics::update()
{
	Draw(GameEngine::entities[0]);
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
