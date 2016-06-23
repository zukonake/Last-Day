#include "world.hpp"

Point2D World::transformPositionToChunkPosition( const Point2D& targetTilePosition )
{
	Point2D output( targetTilePosition );
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

Point2D World::transformPositionToInternalPosition( const Point2D& targetTilePosition )
{
	Point2D output;
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

Chunk World::getChunk( const Point2D& targetTilePosition )
{
	for( unsigned int iterator = 0; iterator < loadedChunks.size(); iterator++ )
	{
		if( loadedChunks[ iterator ].position == transformPositionToChunkPosition( targetTilePosition ))
		{
			return loadedChunks[ iterator ];
		}
	}
	return loadChunk( transformPositionToChunkPosition( targetTilePosition ) );
}

Chunk World::loadChunk( const Point2D& targetChunkPosition )
{
	std::cout << "INFO: Loading chunk: " << targetChunkPosition.x << ", " << targetChunkPosition.y << "\n";
	loadedChunks.push_back( generator.generateChunk( dataset, targetChunkPosition )  );
	return loadedChunks.back();
}

World::World( Dataset& dataset ) : dataset( dataset )
{

}

World::~World()
{

}

Tile* World::operator()( const Point2D& targetTilePosition )
{
	Point2D targetInternalPosition = transformPositionToInternalPosition( targetTilePosition );
	return getChunk( targetTilePosition ).tiles[ targetInternalPosition.x ][ targetInternalPosition.y ];
}
