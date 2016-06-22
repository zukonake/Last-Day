#include "world.hpp"

Point2D World::transformPositionToChunkPosition( const Point2D& targetTilePosition )
{
	return targetTilePosition * Chunk::sizeInTiles;
}

Point2D World::transformPositionToInternalPosition( const Point2D& targetTilePosition )
{
	return targetTilePosition % Chunk::sizeInTiles;
}

Point2D World::transformPositionToTilePosition( const Point2D& targetChunkPosition )
{
	return targetChunkPosition / Chunk::sizeInTiles;
}

Chunk& World::getChunk( const Point2D& targetTilePosition )
{
	for( unsigned int iterator = 0; iterator < loadedChunks.size(); iterator++ )
	{
		if( loadedChunks[ iterator ].position == transformPositionToChunkPosition( targetTilePosition ) )
		{
			return loadedChunks[ iterator ];
		}
	}
	return loadChunk( transformPositionToChunkPosition( targetTilePosition ) );
}

Chunk& World::loadChunk( const Point2D& targetChunkPosition )
{
	loadedChunks.push_back( generator.generateChunk( dataset ) );
	return loadedChunks.back();
}

World::World( const Dataset& dataset ) : dataset( dataset )
{

}

World::~World()
{

}

Tile& World::operator()( const Point2D& targetTilePosition )
{
	return getChunk( targetTilePosition )( transformPositionToInternalPosition( targetTilePosition ) );
}
