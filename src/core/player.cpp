#include "player.hpp"

Player::Player( const Point2D& position, World& world, const MobSubtype& subtype ) :
	Mob( position, world, subtype ),
	camera( Camera( position, world ))
{

}

Player::~Player()
{

}
