#pragma once
#include "subSystem.h" 
#include <enet/enet.h>
class Multiplayer: public subSystem
{

	struct Vector3 {
		float x;
		float y;
		float z;
	};

public:
	Multiplayer();
	~Multiplayer();
	void init();
	void update();

	ENetAddress address;
	ENetHost* client;
	ENetPeer* peer;
	ENetEvent enetEvent;
	Vector3* newPos = new Vector3;
	Vector3 oldPos;
};

