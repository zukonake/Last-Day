#include "player.hpp"

void Player::render( SDL_Surface& targetSurface )
{
	SDL_RectWrapper renderPosition(0,0);
	camera.position = &this->position;
	camera.render( targetSurface, renderPosition );
}

Player::Player( Point2D _position, World& world, const MobSubtype& subtype ) :
	Mob( _position, world, subtype ),
	camera( NULL, world, 7 )
{
}

Player::~Player()
{

}
