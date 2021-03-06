#include "Physics.h"
/*
	- Physics
		movement through terrain
*/

btDiscreteDynamicsWorld* Physics::world;
glm::vec3 Physics::Front;

Physics::Physics()
{	
	
}

Physics::~Physics()
{
	delete world;
	delete solver;
	delete collisionConfiguration;
	delete dispatcher;
	delete broadphase;
}
/*
Math liabry could take these
*/
glm::vec3 convertToVec3(core::vector3df change) {

	glm::vec3 changed = glm::vec3(change.X, change.Y, change.Z);

	return changed;
}
glm::vec3 convertToVec32(btVector3 change) {

	glm::vec3 changed = glm::vec3(change.x(), change.y(), change.z());

	return changed;
}

btVector3 ConvertTobt(glm::vec3 change) {

	btVector3 changed = btVector3(change.x, change.y, change.z);

	return changed;
}

void ChangePos(Event* e) {
	/*
	Update the postion based on the direction we passed in
	Unfortunatly the direction is not based on the mouse forawrd
	*/
	btVector3 update;
	float speed = e->eventInfo.speed;
	
	if (e->eventInfo.dir > 0) {
		speed = -speed;
	}
	if (e->eventInfo.dir == -1 || e->eventInfo.dir == 1) {
		update = btVector3(0, 0, speed);
	}
	else if (e->eventInfo.dir == -2 || e->eventInfo.dir == 2) {
		update = btVector3(speed, 0, 0);
	}
	else if (e->eventInfo.dir == -3 || e->eventInfo.dir == 3) {
		update = btVector3(0, speed, 0);
	}
	/*
	The position is moved via force
	*/
	float force = 3.0f;

	for (int i = 0; i < e->eventInfo.affEntities.size(); i++)
	{
		if (GameEngine::entities[i]->type == EntityEnum(0)) {
			glm::vec3 dir = glm::normalize(convertToVec32(update)) * force; 
			btVector3 dir2 = ConvertTobt(dir);
			e->eventInfo.affEntities[i]->getRigidBody()->applyCentralImpulse(dir2);
		}
	}
	for (int i = 0; i < GameEngine::entities.size(); i++) {

		if (GameEngine::entities[i]->type == EntityEnum(0)) {
			glm::vec3 dir = glm::normalize(convertToVec32(update) ) * force;
			btVector3 dir2 = ConvertTobt(dir);
			GameEngine::entities[i]->getRigidBody()->applyCentralImpulse(dir2);
			GameEngine::entities[i]->getRigidBody()->activate();
		}
	}
}

void addRigidBody(Event* e) {

	/*
	This will give the passed in entity a rigid body based on the event criteria
	Each rigid body is a box 
	*/
	btTransform t;
	t.setIdentity();
	t.setOrigin(btVector3(e->eventInfo.posx, e->eventInfo.posy, e->eventInfo.posz));
	btBoxShape* shape = new btBoxShape(btVector3(e->eventInfo.width / 2, e->eventInfo.height / 2, e->eventInfo.depth / 2));
	btVector3 intertia(0, 0, 0);
	if (e->eventInfo.mass != 0) {
		shape->calculateLocalInertia(e->eventInfo.mass, intertia);
	}
	btMotionState* motion = new btDefaultMotionState(t); // shape 
	btRigidBody::btRigidBodyConstructionInfo info(e->eventInfo.mass, motion, shape, intertia);
	btRigidBody* body = new btRigidBody(info);

	
	e->eventInfo.affEntities[0]->setRigidBody(body);
	for (int i = 0; i < GameEngine::entities.size(); i++) {
		if (e->eventInfo.affEntities[0] == GameEngine::entities[i]) {
			GameEngine::entities[i]->setRigidBody(body);
		}
	}
	Physics::world->addRigidBody(body);
}

void upDateHeader(Event* e) {
	Physics::Front = e->eventInfo.Header;
}


void loadlevel(Event* e) {

	/*
	For each entity if it needs a rigid body create one
	For the map simply create a plane 
	The information to create the boundaries and stuff are passed in by LUA
	*/

	for (int i = 0; i < GameEngine::entities.size(); i++) {
		if (GameEngine::entities[i]->getRigidBody() != nullptr) {
			if (GameEngine::entities[i]->type == EntityEnum(2)) {

				btTransform t;
				t.setIdentity();
				t.setOrigin((btVector3(GameEngine::entities[i]->position.x, GameEngine::entities[i]->position.y, GameEngine::entities[i]->position.z)));
				btStaticPlaneShape* plane = new btStaticPlaneShape(btVector3(0, 1, 0), btScalar(0));
				btMotionState* motion = new btDefaultMotionState(t); // shape 
				btRigidBody::btRigidBodyConstructionInfo info(btScalar(0), motion, plane);
				btRigidBody* body = new btRigidBody(info);
				Physics::world->addRigidBody(body);
			}
			else if (GameEngine::entities[i]->type == EntityEnum(4))
			{
				Event* addBod = new Event(EventTypeEnum(3));
				addBod->eventInfo.affEntities.push_back(GameEngine::entities[i]);
				addBod->eventInfo.mass = GameEngine::entities[i]->getMass();
				addBod->eventInfo.width = GameEngine::entities[i]->getSize() * GameEngine::entities[i]->getScale().x;
				addBod->eventInfo.height = GameEngine::entities[i]->getSize() * GameEngine::entities[i]->getScale().y;
				addBod->eventInfo.depth = GameEngine::entities[i]->getSize() * GameEngine::entities[i]->getScale().z;
				addBod->eventInfo.posx = GameEngine::entities[i]->position.x;
				addBod->eventInfo.posy = GameEngine::entities[i]->position.y;
				addBod->eventInfo.posz = GameEngine::entities[i]->position.z;
				GameEngine::eventQueue.push_back(addBod);
			}
			else {
				Event* addBod = new Event(EventTypeEnum(3));
				addBod->eventInfo.affEntities.push_back(GameEngine::entities[i]);
				addBod->eventInfo.mass = GameEngine::entities[i]->getMass();
				addBod->eventInfo.width = 100;
				addBod->eventInfo.height = 100;
				addBod->eventInfo.depth = 10;
				addBod->eventInfo.posx = GameEngine::entities[i]->position.x;
				addBod->eventInfo.posy = GameEngine::entities[i]->position.y;
				addBod->eventInfo.posz = GameEngine::entities[i]->position.z;
				GameEngine::eventQueue.push_back(addBod);
			}
		}
	}
}

void close(Event* e) {

}

void Physics::init()
{
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfiguration);
	broadphase = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver();
	Physics::world = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
	Physics::world->setGravity(btVector3(0, -9.8, 0));
	
	Event* blank = nullptr;
	loadlevel(blank);

	void(*updateEnity)(Event*) = ChangePos;
	functions[0] = ChangePos;

	void(*closeit)(Event*) = close;
	functions[2] = close;

	void(*addBodies)(Event*) = addRigidBody;
	functions[3] = addRigidBody;

	void(*header)(Event*) = upDateHeader;
	functions[4] = upDateHeader;

	void(*NewLevel)(Event*) = loadlevel;
	functions[5] = loadlevel;
}


void Physics::update()
{

	world->stepSimulation(1/60.0f);


	if (GameEngine::eventQueue.size() != 0) { // if event Q is populated
		for (int i = 0; i < GameEngine::eventQueue.size(); i++) {	// for each event, then for each sub system in each event
			for (int j = 0; j < GameEngine::eventQueue[i]->mySubs.size(); j++) {
				if (GameEngine::eventQueue[i]->mySubs[j] == SubSystemEnum(3)) { // check to see if it need the current subsystem
					functions[int(GameEngine::eventQueue[i]->functPoint)](GameEngine::eventQueue[i]);
					GameEngine::eventQueue[i]->mySubs.erase(GameEngine::eventQueue[i]->mySubs.begin() + j);
				}
			}
		}
	}

}
