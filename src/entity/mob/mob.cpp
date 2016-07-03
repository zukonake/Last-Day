#include "mob.hpp"

Mob::Mob( World& world, const Point& position, MobSubtype* subtype ) noexcept :
	Entity( world, position, subtype )
{

}
