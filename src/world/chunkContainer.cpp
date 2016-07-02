#include "chunkContainer.hpp"

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
	loadedChunks[ targetChunkPosition ] = generator.generateChunk( world, loadedChunks[ targetChunkPosition ], targetChunkPosition );
	return loadedChunks[ targetChunkPosition ];
}

ChunkContainer::~ChunkContainer( void )
{
	unloadChunks();
}

void ChunkContainer::unloadChunks( void )
{

}

void ChunkContainer::unloadChunk( const Point& targetChunkPosition )
{

}
