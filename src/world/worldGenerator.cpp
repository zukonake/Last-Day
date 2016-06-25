#include "worldGenerator.hpp"

Chunk& WorldGenerator::generateChunk( Chunk& target, Dataset& availableDataset )
{
	for( unsigned int iteratorY = 0; iteratorY < Chunk::sizeInTiles; iteratorY++ )
	{
		for( unsigned int iteratorX = 0; iteratorX < Chunk::sizeInTiles; iteratorX++ )
		{
			if( (rand() % 10) == 1)
			{
				target.tiles[ iteratorX ][ iteratorY ] = Tile( 1, &availableDataset.initializedTileSubtypes[ "dirt" ] );
			}
			else
			{
				target.tiles[ iteratorX ][ iteratorY ] = Tile( 1, &availableDataset.initializedTileSubtypes[ "grass" ] );
			}
		}
	}
	return target;
}

WorldGenerator::WorldGenerator()
{

}
