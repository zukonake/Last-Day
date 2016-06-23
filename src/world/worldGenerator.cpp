#include "worldGenerator.hpp"
#include <cstdlib>

Chunk WorldGenerator::generateChunk( Dataset& availableDataset, const Point2D& targetChunkPosition )
{
	Chunk output;
	for( unsigned int iteratorY = 0; iteratorY < Chunk::sizeInTiles; iteratorY++ )
	{
		for( unsigned int iteratorX = 0; iteratorX < Chunk::sizeInTiles; iteratorX++ )
		{
			if( (rand() % 10) == 1)
			{
				output.tiles[ iteratorX ][ iteratorY ] = &availableDataset.initializedTiles[ "dirt" ];
			}
			else
			{
				output.tiles[ iteratorX ][ iteratorY ] = &availableDataset.initializedTiles[ "grass" ];
			}
		}
	}
	output.position = targetChunkPosition;
	return output;
}

WorldGenerator::WorldGenerator()
{

}
