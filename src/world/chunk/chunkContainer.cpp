#include "chunkContainer.hpp"
#include <iostream>
//
#include <geometry/point.hpp>
#include <world/tile/tile.hpp>
#include <entity/entityContainer.hpp>
#include <world/worldGenerator.hpp>

ChunkContainer::ChunkContainer( WorldGenerator& generator, EntityContainer& entityContainer ) noexcept :
	mGenerator( generator ),
	mEntityContainer( entityContainer )
{

}

void ChunkContainer::unloadInactiveChunks( void ) noexcept
{
	std::map< const Point, Chunk* > tempMap;
	for( auto& iChunk : mLoadedChunks )
	{
		tempMap[ iChunk.first ] = &iChunk.second;
	}
	for( auto& iChunk : tempMap )
	{
		if( --iChunk.second->active <= 0 )
		{
			unloadChunk( iChunk.first );
		}
	}
	return;
}

Tile& ChunkContainer::getTile( const Point& targetTilePosition, const bool& chunkAnchor ) noexcept
{
	Point targetInternalPosition = Point::internalPosition( targetTilePosition, Chunk::sizeInTiles );
	Point targetChunkPosition = Point::chunkPosition( targetTilePosition, Chunk::sizeInTiles );
	return getChunk( targetChunkPosition, chunkAnchor ).value[ targetInternalPosition.x ][ targetInternalPosition.y ];
}

Chunk& ChunkContainer::getChunk( const Point& targetChunkPosition, const bool& chunkAnchor ) noexcept
{
	if( mLoadedChunks.find( targetChunkPosition ) == mLoadedChunks.end() )
	{
		loadChunk( targetChunkPosition );
	}
	if( chunkAnchor )
	{
		setNearbyChunksActive( targetChunkPosition );
	}
	return mLoadedChunks[ targetChunkPosition ];
}

void ChunkContainer::setNearbyChunksActive( const Point& targetChunkPosition ) noexcept
{
	for( Point::coordinate iteratorY = targetChunkPosition.y - csChunkActiveRange; iteratorY < targetChunkPosition.y + csChunkActiveRange; iteratorY++ )
	{
		for( Point::coordinate iteratorX = targetChunkPosition.x - csChunkActiveRange; iteratorX < targetChunkPosition.x + csChunkActiveRange; iteratorX++ )
		{
			Point iteratorChunkPosition( iteratorX, iteratorY );
			if( getChunk( iteratorChunkPosition ).active < csChunkActiveThreshold )
			{
				getChunk( iteratorChunkPosition ).active += 1;
			}
		}
	}
}

Chunk& ChunkContainer::loadChunk( const Point& targetChunkPosition ) noexcept
{
	std::cout << "INFO: Loading chunk: " << targetChunkPosition << "\n";
	mGenerator.generateChunk( targetChunkPosition, mLoadedChunks[ targetChunkPosition ] );
	return mLoadedChunks[ targetChunkPosition ];
}

void ChunkContainer::unloadChunk( const Point& targetChunkPosition ) noexcept
{
	if( mLoadedChunks.find( targetChunkPosition ) == mLoadedChunks.end() )
	{
		return;
	}
	std::cout << "INFO: Unloading chunk: " << targetChunkPosition << "\n";
	Point targetTilePosition = Point::tilePosition( targetChunkPosition, Chunk::sizeInTiles );
	for( Point::coordinate iteratorY = targetTilePosition.y; iteratorY < targetTilePosition.y + ( int )Chunk::sizeInTiles; iteratorY++ )
	{
		for( Point::coordinate iteratorX = targetTilePosition.x; iteratorX < targetTilePosition.x + ( int )Chunk::sizeInTiles; iteratorX++ )
		{
			mEntityContainer.removeEntity( { iteratorX, iteratorY } );
		}
	}
	mLoadedChunks.erase( targetChunkPosition );
	return;
}
