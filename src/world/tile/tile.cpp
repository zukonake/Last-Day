#include "tile.hpp"
#include <exception>

void Tile::render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const
{
	if( renderer == nullptr )
	{
		throw std::invalid_argument( "Tile::render, null pointer given in argument 1." );
		return;
	}
	subtype->render( renderer, targetPosition );
	return;
}

const std::string& Tile::getSubtypeName( void ) const noexcept
{
	return subtype->getName();
}

const int8_t& Tile::getHeight( void ) const noexcept
{
	return height;
}
