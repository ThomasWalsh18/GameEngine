#pragma once
#include "subSystem.h"
#include "GameEngine.h"
#include "btBulletDynamicsCommon.h"
class Physics : public subSystem
{
public:
	btBroadphaseInterface* broadphase;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;
	static btDiscreteDynamicsWorld* world;
	static glm::vec3 Front;
	Physics();
	~Physics();
	void init();
	void update();

	void(*functions[6])(Event*);
};

