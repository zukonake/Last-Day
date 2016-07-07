#include "mob.hpp"
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <entity/mob/mobSubtype.hpp>
#include <world/world.hpp>

Mob::Mob( World& world, const Point& position, const MobSubtype* subtype ) noexcept :
	Entity( world, position, subtype )
{

}

void Mob::move( const Direction& targetDirection )
{
	Point positionBefore = mPosition;
	Point positionAfter = mPosition.move( targetDirection.type );
	if( mWorld.canMove( positionAfter ) and targetDirection.type != Direction::NONE )
	{
		mWorld.moveEntity( positionBefore, positionAfter );
		mPosition = positionAfter;
	}
}
