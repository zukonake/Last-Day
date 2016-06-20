#include "world.hpp"

Chunk* World::getChunk( const Point2D& targetTilePosition )
{
	for( auto iterator : loadedChunks )
	{
		if( iterator->position == Chunk::transformPositionToChunkPosition( targetTilePosition ) )
		{
			return iterator;
		}
	}
	return loadChunk( Chunk::transformPositionToChunkPosition( targetTilePosition ) );
}

Chunk* World::loadChunk( const Point2D& targetChunkPosition )
{
	loadedChunks.push_back( new Chunk( targetChunkPosition ) );
}

Tile* World::operator()( const Point2D& targetTilePosition )
{
	return ( *getChunk( targetTilePosition ) )( Chunk::transformPositionToInternalPosition( targetTilePosition ) );
}
