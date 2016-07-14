#include "mob.hpp"
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <entity/mob/mobSubtype.hpp>
#include <world/world.hpp>

Mob::Mob( const Point& position, const MobSubtype* subtype, World& world ) noexcept :
	Entity( position, subtype, world )
{

}

void Mob::move( const Direction& targetDirection )
{
	Point positionAfter = mPosition.move( targetDirection.type );
	if( mWorld.canMove( positionAfter ) )
	{
		mWorld.moveEntity( mPosition, positionAfter );
		mPosition = positionAfter;
	}
}
