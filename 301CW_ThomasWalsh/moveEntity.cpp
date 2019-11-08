#include "moveEntity.h"

moveEntity::moveEntity(glm::vec3 pos, ModelType typeOfModel) : Entity(pos, type)
{
	this->Asset = typeOfModel;
}

moveEntity::~moveEntity()
{

}
