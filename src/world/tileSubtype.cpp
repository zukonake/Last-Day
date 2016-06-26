#include "tileSubtype.hpp"

unsigned int TileSubtype::spriteSize = 32;

void TileSubtype::render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const
{
	if( renderer == NULL )
	{
		throw std::invalid_argument( "ERROR: TileSubtype::render, null pointer given in argument 1." );
		return;
	}
	renderer->renderTileSubtype( this, targetPosition );
	return;
}

TileSubtype::TileSubtype( std::istream& in ) noexcept :
	RenderableObject( in )
{
	in.ignore( 255, ' ' );
	in >> name;
	in >> isPassable;
}
