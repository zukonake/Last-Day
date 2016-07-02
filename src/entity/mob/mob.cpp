#include "mob.hpp"

Mob::Mob( MobSubtype* subtype, World& world, const Point& position ) :
	Entity( subtype, world, position )
{

}

Mob::~Mob()
{

}
