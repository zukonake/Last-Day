#include "worldGenerator.hpp"
#include <cstdlib>
#include <memory>

Chunk::tileArray2D& WorldGenerator::generateTileArray2D( Chunk::tileArray2D& target, Dataset& availableDataset )
{
	for( unsigned int iteratorY = 0; iteratorY < Chunk::sizeInTiles; iteratorY++ )
	{
		for( unsigned int iteratorX = 0; iteratorX < Chunk::sizeInTiles; iteratorX++ )
		{
			if( (rand() % 10) == 1)
			{
				target[ iteratorX ][ iteratorY ] = &availableDataset.initializedTiles[ "dirt" ];
			}
			else
			{
				target[ iteratorX ][ iteratorY ] = &availableDataset.initializedTiles[ "grass" ];
			}
		}
	}
	return target;
}

WorldGenerator::WorldGenerator()
{

}
