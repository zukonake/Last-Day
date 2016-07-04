#include "mob.hpp"

Mob::Mob( World& world, const Point& position, const MobSubtype* subtype ) noexcept :
	Entity( world, position, subtype )
{

}
