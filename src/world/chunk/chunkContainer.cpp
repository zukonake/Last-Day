#include "chunkContainer.hpp"

ChunkContainer::ChunkContainer( WorldGenerator& generator ) noexcept :
	generator( generator )
{

}

Tile& ChunkContainer::getTile( const Point& targetTilePosition )
{
	Point targetInternalPosition = targetTilePosition.internalPosition( Chunk::sizeInTiles );
	Point targetChunkPosition = targetTilePosition.chunkPosition( Chunk::sizeInTiles );
	return getChunk( targetChunkPosition ).tiles[ targetInternalPosition.x ][ targetInternalPosition.y ];
}

Chunk& ChunkContainer::getChunk( const Point& targetChunkPosition )
{
	if( loadedChunks.find( targetChunkPosition ) == loadedChunks.end() )
	{
		loadChunk( targetChunkPosition );
	}
	return loadedChunks[ targetChunkPosition ];
}

Chunk& ChunkContainer::loadChunk( const Point& targetChunkPosition )
{
	generator.generateChunk( loadedChunks[ targetChunkPosition ], targetChunkPosition );
	return loadedChunks[ targetChunkPosition ];
}
