#include "entity.h"

#include <iostream>

/*
Every entity is either idle, active or passive. 

IDLE: 
An idle entity is neither rendered nor interactable. 
For an example if a player has to get to a certain point to the map 
before an object appears, that entity is considered idle.

PASSIVE:
A passive entity is an entity which is only rendered but never interracted with.
For an example if there's ambience such as rain, that entity is considered passive
since it's being rendered but is not interracting with any other entity.

ACTIVE: 
The enitity is both rendered and interracted with. 

In every frame, idle, passive and active entitites are updated. 
Both active and passive entities are sent to the renderer.
Only active entities are sent to the physics engine.

TODO: How to deal with for an example invisible items

*/

entity::entity()
{
}


entity::~entity()
{
}

void entity::update()
{
	std::cout << "entity update. " << std::endl;
}

void entity::draw()
{
	std::cout << "entity draw. " << std::endl;
}