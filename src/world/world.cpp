#include "world.hpp"

std::shared_ptr< Chunk > World::getChunk( const Point& targetTilePosition )
{
	Point targetChunkPosition = targetTilePosition.chunkPosition( Chunk::sizeInTiles );
	if( !loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ] )
	{
		loadChunk( targetChunkPosition );
	}
	return loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ];
}

std::shared_ptr< Chunk > World::loadChunk( const Point& targetChunkPosition )
{
	std::cout << "INFO: Loading chunk: " << targetChunkPosition.x << ", " << targetChunkPosition.y << "\n";
	loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ] = std::make_shared< Chunk > ( Chunk() );
	generator.generateChunk( *loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ], targetChunkPosition );
	return loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ];
}

void World::unloadChunk( const Point& targetChunkPosition )
{

}

void World::renderTile( const Point& targetTilePosition, ObjectRenderer* objectRenderer, SDL_Rect& targetRenderPosition )
{
	uint8_t maximumAlpha = 150;
	double heightAlphaMultiplier = maximumAlpha / ( (generator.getMaximumTileHeight() * 2 ));
	Tile* targetTile = this->operator()( targetTilePosition );
	targetTile->render( objectRenderer, targetRenderPosition );
	int8_t alpha = ( targetTile->getHeight() + generator.getMaximumTileHeight() );
	double alphaModifier = heightAlphaMultiplier * alpha;
	if( alphaModifier > maximumAlpha )
	{
		alphaModifier = maximumAlpha;
	}
	//if( targetTile->getSubtypeName() == "Water")
	//{
		SDL_SetRenderDrawColor( objectRenderer->getRenderer(), 0, 0, 0, maximumAlpha - alphaModifier ) ;
		SDL_RenderFillRect( objectRenderer->getRenderer(), &targetRenderPosition );
	//}
	SDL_SetRenderDrawColor( objectRenderer->getRenderer(), 0, 0, 0, 63 );
	if( this->operator()( Point( targetTilePosition.x - 1, targetTilePosition.y ) )->getHeight() != targetTile->getHeight() )
	{
		SDL_RenderDrawLine( objectRenderer->getRenderer(),
			targetRenderPosition.x,
			targetRenderPosition.y,
			targetRenderPosition.x,
			targetRenderPosition.y + targetRenderPosition.h);
	}
	if( this->operator()( Point( targetTilePosition.x, targetTilePosition.y - 1) )->getHeight() != targetTile->getHeight() )
	{
		SDL_RenderDrawLine( objectRenderer->getRenderer(),
			targetRenderPosition.x,
			targetRenderPosition.y,
			targetRenderPosition.x + targetRenderPosition.w,
			targetRenderPosition.y);
	}
}

World::World( Dataset& dataset ) :
	dataset( dataset ),
	generator( dataset )
{

}

World::~World()
{
	for( auto iteratorY = loadedChunks.begin(); iteratorY != loadedChunks.end(); iteratorY++ )
	{
		for( auto iteratorX = iteratorY->second.begin(); iteratorX != iteratorY->second.end(); iteratorX++ )
		{
			iteratorX->second.reset();
		}
	}
}

Tile* World::operator()( const Point& targetTilePosition )
{
	Point targetInternalPosition = targetTilePosition.internalPosition( Chunk::sizeInTiles );
	return &getChunk( targetTilePosition )->tiles[ targetInternalPosition.x ][ targetInternalPosition.y ];
}
