#include "mob.hpp"
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <entity/mob/mobSubtype.hpp>
#include <world/world.hpp>

Mob::Mob( World& world, const Point& position, MobSubtype* subtype ) noexcept :
	Entity( world, position, subtype )
{

}

void Mob::move( const Direction& targetDirection )
{
	Point positionBefore = position;
	Point positionAfter = position.move( targetDirection.value );
	if( world.canMove( positionAfter ) and targetDirection.value != Direction::NONE )
	{
		world.moveEntity( positionBefore, positionAfter );
		position = position.move( targetDirection );
	}
}
