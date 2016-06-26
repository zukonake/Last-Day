#include "tile.hpp"

void Tile::render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const
{
	if( renderer == NULL )
	{
		throw std::invalid_argument( "ERROR: Tile::render, null pointer given in argument 1." );
		return;
	}
	subtype->render( renderer, targetPosition );
	return;
}
