#include "player.hpp"
#include <data/dataset.hpp>
#include <entity/mob/mob.hpp>
#include <world/tile/tile.hpp>
#include <world/world.hpp>

class MobSubtype;

Player::Player( const Point& position, World& world, Point windowSize, const Dataset& dataset ) noexcept :
	Camera( position, world, windowSize ),
	mDataset( dataset )
{

}

void Player::placeEntity( const Point& position ) noexcept
{
	//mWorld.addEntity< Mob >( Camera::getPositionMouseIsOn( position ), &mDataset.getObject< MobSubtype >( "human" ), mWorld );
	mWorld.getTile( Camera::getPositionMouseIsOn( position  ) ).setSubtype( &mDataset.getObject< TileSubtype >( "wall" ) ); //TODO
	return;
}
