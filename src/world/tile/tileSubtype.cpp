#include "tileSubtype.hpp"
#include <exception>
#include <render/objectRenderer/objectRenderer.hpp>

uint8_t TileSubtype::spriteSize = 32;

TileSubtype::TileSubtype( std::istream& in ) noexcept :
	RenderableObject( in )
{
	in.ignore( 255, ' ' );
	in >> name;
	in.ignore( 255, ' ' );
	in >> isPassable;
}

void TileSubtype::render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const
{
	if( renderer == nullptr )
	{
		throw std::invalid_argument( "TileSubtype::render, null pointer given in argument 1." );
		return;
	}
	renderer->renderTileSubtype( this, targetPosition );
	return;
}

const std::string& TileSubtype::getName( void ) const noexcept
{
	return name;
}

const bool& TileSubtype::getIsPassable( void ) const noexcept
{
	return isPassable;
}
