#include "world.hpp"
#include <iostream>

Point World::transformPositionToChunkPosition( const Point& targetTilePosition )
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

Point World::transformPositionToInternalPosition( const Point& targetTilePosition )
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
	Point targetChunkPosition = transformPositionToChunkPosition( targetTilePosition );
	for( auto iterator : loadedChunks )
	{
		if( iterator->position == targetChunkPosition )
		{
			return iterator;
		}
	}
	return loadChunk( targetChunkPosition );
}

std::shared_ptr< Chunk > World::loadChunk( const Point& targetChunkPosition )
{
	std::cout << "INFO: Loading chunk: " << targetChunkPosition.x << ", " << targetChunkPosition.y << "\n";
	loadedChunks.push_back( std::make_shared< Chunk > ( Chunk( targetChunkPosition ) ) );
	generator.generateTileArray2D( loadedChunks.back()->tiles, dataset );
	return loadedChunks.back();
}

void World::unloadChunk( uint16_t id )
{
	if( loadedChunks[ id ] )
	{
		loadedChunks.erase( loadedChunks.begin() + id );
	}
}

World::World( Dataset& dataset ) : dataset( dataset )
{

}

World::~World()
{
	for( uint16_t iterator = 0; iterator < loadedChunks.size(); iterator++ )
	{
		unloadChunk( iterator );
	}
}

Tile* World::operator()( const Point& targetTilePosition )
{
	Point targetInternalPosition = transformPositionToInternalPosition( targetTilePosition );
	return getChunk( targetTilePosition )->tiles[ targetInternalPosition.x ][ targetInternalPosition.y ];
}
