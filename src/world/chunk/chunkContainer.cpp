#include "chunkContainer.hpp"
#include <geometry/point.hpp>
#include <world/tile/tile.hpp>
#include <world/worldGenerator.hpp>

ChunkContainer::ChunkContainer( WorldGenerator& generator ) noexcept :
	mGenerator( generator )
{

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
