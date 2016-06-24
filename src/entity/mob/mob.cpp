#include "mob.hpp"

Mob::Mob( const Point& position, World& world, const MobSubtype& subtype ) :
	Entity< MobSubtype >( position, world, subtype )
{

}

Mob::~Mob()
{

}
