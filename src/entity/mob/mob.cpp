#include "mob.hpp"

Mob::Mob( const Point& position, World& world, std::shared_ptr < MobSubtype > subtype ) :
	Entity< MobSubtype >( position, world, subtype )
{

}

Mob::~Mob()
{

}
