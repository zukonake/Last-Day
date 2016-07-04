#include "world.hpp"
#include <geometry/direction.hpp>
#include <world/worldGenerator.hpp>

World::World( Dataset& dataset ) noexcept :
	EntityContainer(),
	dataset( dataset ),
	generator( *this ),
	chunkContainer( generator )
{

}

void World::renderHeightEffects( const Point& targetTilePosition, ObjectRenderer* objectRenderer, SDL_Rect& targetRenderPosition ) noexcept
{
	uint8_t maximumAlpha = 150;
	double heightAlphaMultiplier = maximumAlpha / ( (WorldGenerator::getMaximumTileHeight() * 2 ));
	const Tile& targetTile = chunkContainer.getTile( targetTilePosition );
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
	return;
}

void World::simulate( void ) noexcept
{
	EntityContainer::simulate();
	return;
}

const Dataset& World::getDataset( void ) const noexcept
{
	return dataset;
}

Tile& World::getTile( const Point& targetTilePosition ) noexcept
{
	return chunkContainer.getTile( targetTilePosition );
}
