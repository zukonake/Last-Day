#include "world.hpp"

std::shared_ptr< Chunk > World::getChunk( const Point& targetTilePosition )
{
	Point targetChunkPosition = targetTilePosition.chunkPosition( Chunk::sizeInTiles );
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
	generator.generateChunk( *loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ], dataset, targetChunkPosition );
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
	Point targetInternalPosition = targetTilePosition.internalPosition( Chunk::sizeInTiles );
	return &getChunk( targetTilePosition )->tiles[ targetInternalPosition.x ][ targetInternalPosition.y ];
}
