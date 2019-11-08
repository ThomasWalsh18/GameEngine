#pragma once
#include "EntityEnum.h"
#include <glm.hpp>


class Entity 
{
public:
	enum ModelType {
		Character,
		Map,
		Map2,
		Vehical
	};
	Entity(glm::vec3 pos, EntityEnum type);
	~Entity();
	glm::vec3 position;
	EntityEnum type;
};

/*

	Models in whenever avaialble

	__________________________________________________________________________________________________________________________________

	Entity solutions and Asset Management

	So for this problem you can include Irrclight into a drawable entity class, this will allow for differnet meshes to be passed in.
	A better way to do this is to have a asset manager class this class will load everything once and store pointers to it in a map
	then graphics can acess the map's value (as it has a value that corrisponds to the key) so when creating one I pass in
	the key to the mesh I need to create, and then in graphics I just deal with the entites. 
	http://www.cplusplus.com/reference/map/map/map/ 
	__________________________________________________________________________________________________________________________________

	Then add lua
	___________________________________________________________________________________________________________________________________

	Then try the mouse movement 
	___________________________________________________________________________________________________________________________________

	Then audio 
	___________________________________________________________________________________________________________________________________

	Physics
	___________________________________________________________________________________________________________________________________

	Then game logic
	___________________________________________________________________________________________________________________________________

	Networking bruh
*/

