#include "world.hpp"

Point2D World::transformPositionToChunkPosition( const Point2D& targetTilePosition )
{
	return targetTilePosition * Chunk::chunkSizeInTiles;
}

Point2D World::transformPositionToInternalPosition( const Point2D& targetTilePosition )
{
	return targetTilePosition % Chunk::chunkSizeInTiles;
}

Point2D World::transformPositionToTilePosition( const Point2D& targetChunkPosition )
{
	return targetChunkPosition / Chunk::chunkSizeInTiles;
}

Chunk* World::getChunk( const Point2D& targetTilePosition )
{
	for( auto iterator : loadedChunks )
	{
		if( iterator->position == transformPositionToChunkPosition( targetTilePosition ) )
		{
			return iterator;
		}
	}
	return loadChunk( transformPositionToChunkPosition( targetTilePosition ) );
}

Chunk* World::loadChunk( const Point2D& targetChunkPosition )
{
	loadedChunks.push_back( new Chunk( targetChunkPosition ) );
}

World::World() : generator( new WorldGenerator() )
{

}

World::~World()
{
	delete generator;
}

Tile* World::operator()( const Point2D& targetTilePosition )
{
	return ( *getChunk( targetTilePosition ) )( transformPositionToInternalPosition( targetTilePosition ) );
}
