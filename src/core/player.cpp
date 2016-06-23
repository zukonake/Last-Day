#include "player.hpp"

void Player::render( SDL_Surface& targetSurface ) const
{
	SDL_RectWrapper renderPosition(0,0);
	camera.render( targetSurface, renderPosition );
}

Point2D Player::getPosition() const
{
	return position;
}

Player::Player( Point2D _position, World& world, const MobSubtype& subtype ) :
	Mob( _position, world, subtype ),
	camera( position, world, 7 )
{

}

Player::~Player()
{

}
