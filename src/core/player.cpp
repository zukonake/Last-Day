#include "player.hpp"

Player::Player( const Point& position, World& world, const Rectangle& screenSize, const Dataset& dataset ) noexcept :
	Camera( position, world, screenSize ),
	mDataset( dataset )
{

}

void Player::placeMob( const Point& position ) noexcept
{
	//world.addEntity(  )
}
