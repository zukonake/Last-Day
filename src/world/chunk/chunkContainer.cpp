#include "chunkContainer.hpp"
#include <geometry/point.hpp>
#include <world/tile/tile.hpp>
#include <world/worldGenerator.hpp>

ChunkContainer::ChunkContainer( WorldGenerator& generator ) noexcept :
	generator( generator )
{

}

void ChunkContainer::moveEntity( const Point& sourcePosition, const Point& targetPosition )
{
	Tile& sourceTile = getTile( sourcePosition );
	Tile& targetTile = getTile( targetPosition );
	targetTile.setEntity( sourceTile.getEntity() );
	sourceTile.setEntity( nullptr );
	return;
}

bool ChunkContainer::canMove( const Point& targetPosition )
{
	Tile& targetTile = getTile( targetPosition );
	if( targetTile.getEntity() == nullptr and targetTile.isPassable() )
	{
		return true;
	}
	return false;
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
	generator.generateChunk( targetChunkPosition, loadedChunks[ targetChunkPosition ] );
	return loadedChunks[ targetChunkPosition ];
}
