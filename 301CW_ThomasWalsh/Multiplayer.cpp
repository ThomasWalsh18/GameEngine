#include "Multiplayer.h"
/*	- Multiplayer */

Multiplayer::Multiplayer()
{
}

Multiplayer::~Multiplayer()
{
	enet_host_destroy(client);
	atexit(enet_deinitialize);
}

void Multiplayer::init()
{
	if (enet_initialize() != 0)
	{
		std::cout << "Enet failed to initialise!" << "\n\n";
	}

	client = enet_host_create(NULL, 1, 2, 0, 0);

	if (client == NULL)
	{
		std::cout << "Client failed to initialise!" << std::endl;
	}

	enet_address_set_host(&address, "localhost");
	address.port = 1234;

	peer = enet_host_connect(client, &address, 2, 0);

	if (peer == NULL) {
		std::cout << "No available peers for initializing an ENet connection." << std::endl;
	}
}

void Multiplayer::update()
{

	while (enet_host_service(client, &enetEvent, 0) > 0)
	{
		switch (enetEvent.type) {


		case ENET_EVENT_TYPE_RECEIVE:
			memcpy(newPos, enetEvent.packet->data, enetEvent.packet->dataLength);
			if (oldPos.z == newPos->z) {

			}
			else {
				std::cout << "Packet received!" << std::endl;
				std::cout << newPos->x << "," << newPos->y << "," << newPos->z << std::endl;
				oldPos.x = newPos->x;
				oldPos.y = newPos->y;
				oldPos.z = newPos->z;
			}

			//enemy.setPosition(sf::Vector2f(newPosition->x, newPosition->y));
			break;
		}
	}
}
