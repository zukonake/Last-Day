#include "chunkContainer.hpp"
#include <geometry/point.hpp>
#include <world/tile/tile.hpp>
#include <world/worldGenerator.hpp>

ChunkContainer::ChunkContainer( WorldGenerator& generator ) noexcept :
	mGenerator( generator )
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
	Point targetInternalPosition = targetTilePosition.internalPosition( Chunk::getSizeInTiles() );
	Point targetChunkPosition = targetTilePosition.chunkPosition( Chunk::getSizeInTiles() );
	return getChunk( targetChunkPosition ).value[ targetInternalPosition.x ][ targetInternalPosition.y ];
}

Chunk& ChunkContainer::getChunk( const Point& targetChunkPosition )
{
	if( mLoadedChunks.find( targetChunkPosition ) == mLoadedChunks.end() )
	{
		loadChunk( targetChunkPosition );
	}
	return mLoadedChunks[ targetChunkPosition ];
}

Chunk& ChunkContainer::loadChunk( const Point& targetChunkPosition )
{
	mGenerator.generateChunk( targetChunkPosition, mLoadedChunks[ targetChunkPosition ] );
	return mLoadedChunks[ targetChunkPosition ];
}
