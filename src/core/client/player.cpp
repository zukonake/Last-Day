#include "player.hpp"
#include <geometry/SDL_RectWrapper.hpp>

void Player::render( SDL_Renderer* targetRenderer )
{
	SDL_RectWrapper renderPosition(0,0);
	Camera::render( targetRenderer );
}

Player::Player( const Point& position, World& world ) :
	Camera( position, world )
{

}

Player::~Player()
{

}
