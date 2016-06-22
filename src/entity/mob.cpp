#include "mob.hpp"

Mob::Mob( Point2D position, World& world, const MobSubtype& subtype ) : Entity< MobSubtype >( position, world, subtype )
{

}

Mob::~Mob()
{

}
