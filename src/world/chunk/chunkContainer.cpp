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
	Point targetInternalPosition = targetTilePosition.internalPosition( Chunk::getSizeInTiles() );
	Point targetChunkPosition = targetTilePosition.chunkPosition( Chunk::getSizeInTiles() );
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
	std::cout << "INFO: Loading chunk: " << targetChunkPosition.x << ", " << targetChunkPosition.y << "\n";
	mGenerator.generateChunk( targetChunkPosition, mLoadedChunks[ targetChunkPosition ] );
	return mLoadedChunks[ targetChunkPosition ];
}

void ChunkContainer::unloadChunk( const Point& targetChunkPosition ) noexcept
{
	if( mLoadedChunks.find( targetChunkPosition ) == mLoadedChunks.end() )
	{
		return;
	}
	std::cout << "INFO: Unloading chunk: " << targetChunkPosition.x << ", " << targetChunkPosition.y << "\n";
	Point targetTilePosition = targetChunkPosition.tilePosition( Chunk::getSizeInTiles() );
	for( Point::coordinate iteratorY = targetTilePosition.y; iteratorY < targetTilePosition.y + ( int )Chunk::getSizeInTiles(); iteratorY++ )
	{
		for( Point::coordinate iteratorX = targetTilePosition.x; iteratorX < targetTilePosition.x + ( int )Chunk::getSizeInTiles(); iteratorX++ )
		{
			mEntityContainer.removeEntity( Point( iteratorX, iteratorY ) );
		}
	}
	mLoadedChunks.erase( targetChunkPosition );
	return;
}
