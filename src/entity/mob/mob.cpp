#include "mob.hpp"

Mob::Mob( MobSubtype* subtype, const Point& position, World& world ) :
	Entity( subtype, position, world )
{

}

Mob::~Mob()
{

}
