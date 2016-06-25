#include "tile.hpp"

void Tile::render( SDL_Renderer* targetRenderer, SDL_Rect& targetPosition )
{
	if( subtype )
	{
		subtype->render( targetRenderer, targetPosition );
	}
}

Tile::Tile( int8_t height, TileSubtype* subtype ) :
	height( height ),
	subtype( subtype )
{

}

Tile::Tile() :
	subtype( NULL )
{

}

Tile::~Tile()
{

}
