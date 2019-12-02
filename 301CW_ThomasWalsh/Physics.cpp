#include "Physics.h"
/*
	- Physics
		shooting
		movement through water and other terrain, moving with damage
*/

Physics::Physics()
{	
	
}

Physics::~Physics()
{
}
glm::vec3 convertToVec3(core::vector3df change) {

	glm::vec3 changed = glm::vec3(change.X, change.Y, change.Z);

	return changed;
}

void ChangePos(Event* e) {
	core::vector3df update;
	float speed = e->eventInfo.speed;
	
	if (e->eventInfo.dir > 0) {
		speed = -speed;
	}
	if (e->eventInfo.dir == -1 || e->eventInfo.dir == 1) {
		update = core::vector3df(0, 0, speed);
	}
	else if (e->eventInfo.dir == -2 || e->eventInfo.dir == 2) {
		update = core::vector3df(speed, 0, 0);
	}
	else if (e->eventInfo.dir == -3 || e->eventInfo.dir == 3) {
		update = core::vector3df(0, speed, 0);
	}

	for (int i = 0; i < e->eventInfo.affEntities.size(); i++)
	{
		e->eventInfo.affEntities[i]->position += convertToVec3(update);
	}
	for (int i = 0; i < GameEngine::entities.size(); i++) {
		if (GameEngine::entities[i]->type == EntityEnum(1)) {
			GameEngine::entities[i]->position += convertToVec3(update);
		}
	}
}

void Physics::init()
{
	//broadphase = new btDbvtBroadphase();
	//collisionConfiguration = new btDefaultCollisionConfiguration();
	//dispatcher = new btCollisionDispatcher(collisionConfiguration);
	//solver = new btSequentialImpulseConstraintSolver();
	//world = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
	//world->setGravity(btVector3(0, -9.8, 0));
	//https://www.raywenderlich.com/2606-bullet-physics-tutorial-getting-started 

	void(*updateEnity)(Event*) = ChangePos;
	GameEngine::functions[0] = ChangePos;

}


void Physics::update()
{
	if (GameEngine::eventQueue.size() != 0) { // if event Q is populated
		for (int i = 0; i < GameEngine::eventQueue.size(); i++) {	// for each event, then for each sub system in each event
			for (int j = 0; j < GameEngine::eventQueue[i]->mySubs.size(); j++) {
				if (GameEngine::eventQueue[i]->mySubs[j] == SubSystemEnum(3)) { // check to see if it need the current subsystem
					GameEngine::functions[int(GameEngine::eventQueue[i]->functPoint)](GameEngine::eventQueue[i]);
					GameEngine::eventQueue[i]->mySubs.erase(GameEngine::eventQueue[i]->mySubs.begin() + j);
				}
			}
		}
	}

}
