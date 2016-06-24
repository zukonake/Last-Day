#include "player.hpp"
#include <geometry/SDL_RectWrapper.hpp>

void Player::render( SDL_Surface& targetSurface )
{
	SDL_RectWrapper renderPosition(0,0);
	Camera::render( targetSurface );
}

Player::Player( const Point& position, World& world ) :
	Camera( position, world )
{

}

Player::~Player()
{

}
