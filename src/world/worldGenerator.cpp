#include "worldGenerator.hpp"

Chunk& WorldGenerator::generateChunk( Chunk& target, Dataset& availableDataset, const Point& targetChunkPosition )
{
	for( unsigned int iteratorY = 0; iteratorY < Chunk::sizeInTiles; iteratorY++ )
	{
		for( unsigned int iteratorX = 0; iteratorX < Chunk::sizeInTiles; iteratorX++ )
		{
			Point firstTile = targetChunkPosition.tilePosition( Chunk::sizeInTiles );
			double heightValue = perlinNoise.GetValue( (double)( firstTile.x + (int)iteratorX ) / 10, (double)( firstTile.y + (int)iteratorY ) / 10, 0 );
			if( heightValue >= 0.55 )
			{
				target.tiles[ iteratorX ][ iteratorY ] = Tile( &availableDataset.initializedTileSubtypes[ "stone" ], heightValue*25);
			}
			else if( heightValue >= 0.3 )
			{
				target.tiles[ iteratorX ][ iteratorY ] = Tile( &availableDataset.initializedTileSubtypes[ "dirt" ], heightValue*25);
			}
			else if( heightValue >= -0.1 )
			{
				target.tiles[ iteratorX ][ iteratorY ] = Tile( &availableDataset.initializedTileSubtypes[ "grass" ], heightValue*25);
			}
			else if( heightValue >= -0.2 )
			{
				target.tiles[ iteratorX ][ iteratorY ] = Tile( &availableDataset.initializedTileSubtypes[ "sand" ], heightValue*25);
			}
			else if( heightValue < -0.2 )
			{
				target.tiles[ iteratorX ][ iteratorY ] = Tile( &availableDataset.initializedTileSubtypes[ "water" ], heightValue*25);
			}
		}
	}
	return target;
}

WorldGenerator::WorldGenerator()
{
	perlinNoise.SetPersistence( 0.3 );
	perlinNoise.SetFrequency( 0.1 );
}
