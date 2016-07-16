#include "player.hpp"
#include <data/dataset.hpp>
#include <entity/mob/mob.hpp>
#include <world/world.hpp>
#include <iostream> //TODO

class MobSubtype;

Player::Player( const Point& position, World& world, const Rectangle& screenSize, const Dataset& dataset ) noexcept :
	Camera( position, world, screenSize ),
	mDataset( dataset )
{

}

void Player::placeMob( const Point& position ) noexcept
{
	//mWorld.addEntity< Mob >( Camera::getPositionMouseIsOn( position ), mDataset.getObject< MobSubtype >( "human" ), mWorld );
	mWorld.getTile( Camera::getPositionMouseIsOn( position  ) ).setSubtype( mDataset.getObject< TileSubtype >( "wall" ) ); //TODO
	return;
}
