#include "tile.hpp"

void Tile::render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const
{
	if( renderer == nullptr )
	{
		throw std::invalid_argument( "Tile::render, null pointer given in argument 1." );
		return;
	}
	subtype->render( renderer, targetPosition );
	if( entity != nullptr )
	{
		entity->render( renderer, targetPosition );
	}
	return;
}
