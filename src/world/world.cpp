#include "world.hpp"

Chunk* World::getChunk( Point2D targetTilePosition )
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

Chunk* World::loadChunk( Point2D targetChunkPosition )
{
	loadedChunks.push_back( new Chunk( targetChunkPosition ) );
}

Tile* World::operator()( Point2D targetTilePosition )
{
	return ( *getChunk( targetTilePosition ) )( Chunk::transformPositionToInternalPosition( targetTilePosition ) );
}
