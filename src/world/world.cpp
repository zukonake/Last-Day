#include "world.hpp"
#include <iostream>

Point World::chunkPosition( const Point& targetTilePosition )
{
	Point output( targetTilePosition );
	if( output.x < 0 )
	{
		output.x -= Chunk::sizeInTiles - 1;
	}
	if( output.y < 0 )
	{
		output.y -= Chunk::sizeInTiles - 1;
	}
	output = output / Chunk::sizeInTiles;
	return output;
}

Point World::internalPosition( const Point& targetTilePosition )
{
	Point output;
	output = targetTilePosition % Chunk::sizeInTiles;
	if( output.x < 0 )
	{
		output.x += Chunk::sizeInTiles;
	}
	if( output.y < 0 )
	{
		output.y += Chunk::sizeInTiles;
	}
	return output;
}

std::shared_ptr< Chunk > World::getChunk( const Point& targetTilePosition )
{
	Point targetChunkPosition = chunkPosition( targetTilePosition );
	if( !loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ] )
	{
		loadChunk( targetChunkPosition );
	}
	return loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ];
}

std::shared_ptr< Chunk > World::loadChunk( const Point& targetChunkPosition )
{
	std::cout << "INFO: Loading chunk: " << targetChunkPosition.x << ", " << targetChunkPosition.y << "\n";
	loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ] = std::make_shared< Chunk > ( Chunk() );
	generator.generateTileArray2D( loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ]->tiles, dataset );
	return loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ];
}

World::World( Dataset& dataset ) : dataset( dataset )
{

}

World::~World()
{

}

Tile* World::operator()( const Point& targetTilePosition )
{
	Point targetInternalPosition = internalPosition( targetTilePosition );
	return getChunk( targetTilePosition )->tiles[ targetInternalPosition.x ][ targetInternalPosition.y ];
}
