#include "mob.hpp"

Mob::Mob( MobSubtype* subtype, const Point& position ) :
	Entity( subtype, position )
{

}

Mob::~Mob()
{

}
