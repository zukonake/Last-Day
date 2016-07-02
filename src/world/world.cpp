#include "world.hpp"

void World::renderHeightEffects( const Point& targetTilePosition, ObjectRenderer* objectRenderer, SDL_Rect& targetRenderPosition )
{
	uint8_t maximumAlpha = 150;
	double heightAlphaMultiplier = maximumAlpha / ( (WorldGenerator::getMaximumTileHeight() * 2 ));
	Tile& targetTile = chunkContainer.getTile( targetTilePosition );
	int8_t alpha = ( targetTile.getHeight() + WorldGenerator::getMaximumTileHeight() );
	double alphaModifier = heightAlphaMultiplier * alpha;
	if( alphaModifier > maximumAlpha )
	{
		alphaModifier = maximumAlpha;
	}
	SDL_SetRenderDrawColor( objectRenderer->getRenderer(), 0, 0, 0, maximumAlpha - alphaModifier ) ;
	SDL_RenderFillRect( objectRenderer->getRenderer(), &targetRenderPosition );
	SDL_SetRenderDrawColor( objectRenderer->getRenderer(), 0, 0, 0, 63 );
	if( chunkContainer.getTile( Point( targetTilePosition.x - 1, targetTilePosition.y ) ).getHeight() != targetTile.getHeight() )
	{
		SDL_RenderDrawLine( objectRenderer->getRenderer(),
			targetRenderPosition.x,
			targetRenderPosition.y,
			targetRenderPosition.x,
			targetRenderPosition.y + targetRenderPosition.h);
	}
	if( chunkContainer.getTile( Point( targetTilePosition.x, targetTilePosition.y - 1) ).getHeight() != targetTile.getHeight() )
	{
		SDL_RenderDrawLine( objectRenderer->getRenderer(),
			targetRenderPosition.x,
			targetRenderPosition.y,
			targetRenderPosition.x + targetRenderPosition.w,
			targetRenderPosition.y);
	}
}

Tile& World::getTile( const Point& targetTilePosition )
{
	return chunkContainer.getTile( targetTilePosition );
}

void World::simulate( void )
{

}

World::World( Dataset& dataset ) :
	EntityContainer(),
	chunkContainer( *this, dataset, dynamic_cast< EntityContainer& >( *this ) )
{

}

World::~World()
{

}
