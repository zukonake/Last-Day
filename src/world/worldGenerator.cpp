#include "worldGenerator.hpp"

Chunk& WorldGenerator::generateChunk( Chunk& target, const Point& targetChunkPosition )
{
	for( unsigned int iteratorY = 0; iteratorY < Chunk::sizeInTiles; iteratorY++ )
	{
		for( unsigned int iteratorX = 0; iteratorX < Chunk::sizeInTiles; iteratorX++ )
		{
			Point firstTile = targetChunkPosition.tilePosition( Chunk::sizeInTiles );
			double heightValue = finalTerrain.GetValue( (double)( firstTile.x + (int)iteratorX ) / scale, (double)( firstTile.y + (int)iteratorY ) / scale, 0 );
			if( heightValue >= 0.55 )
			{
				target.tiles[ iteratorX ][ iteratorY ] = Tile( &availableDataset.initializedTileSubtypes[ "stone" ], heightValue*heightMultiplier);
			}
			else if( heightValue >= 0.5 )
			{
				target.tiles[ iteratorX ][ iteratorY ] = Tile( &availableDataset.initializedTileSubtypes[ "dirt" ], heightValue*heightMultiplier);
			}
			else if( heightValue >= -0.1 )
			{
				target.tiles[ iteratorX ][ iteratorY ] = Tile( &availableDataset.initializedTileSubtypes[ "grass" ], heightValue*heightMultiplier);
			}
			else if( heightValue >= -0.2 )
			{
				target.tiles[ iteratorX ][ iteratorY ] = Tile( &availableDataset.initializedTileSubtypes[ "sand" ], heightValue*heightMultiplier);
			}
			else if( heightValue < -0.2 )
			{
				target.tiles[ iteratorX ][ iteratorY ] = Tile( &availableDataset.initializedTileSubtypes[ "water" ], heightValue*heightMultiplier);
			}
		}
	}
	return target;
}

int WorldGenerator::getMaximumTileHeight()
{
	return ( int )( heightMultiplier );
}

WorldGenerator::WorldGenerator( Dataset& availableDataset ) :
	availableDataset( availableDataset )
{
	flatTerrain.SetFrequency( 0.25 );
	mountainTerrain.SetFrequency( 0.5 );
	terrainType.SetFrequency( 0.1 );
	terrainType.SetPersistence( 0.5 );
	terrainType.SetOctaveCount( 16 );
	scaledSeaTerrain.SetSourceModule( 0, seaTerrain );
	scaledSeaTerrain.SetScale( 0.15 );
	scaledSeaTerrain.SetBias( -0.8 );
	scaledFlatTerrain.SetSourceModule( 0, flatTerrain );
	scaledFlatTerrain.SetScale( 0.2 );
	scaledFlatTerrain.SetBias( 0.14 );
	scaledMountainTerrain.SetSourceModule( 0, mountainTerrain );
	scaledMountainTerrain.SetScale( 1.2 );
	scaledMountainTerrain.SetBias( 0.35 );
	scaledTerrainType.SetSourceModule( 0, terrainType );
	scaledTerrainType.SetScale( 0.85 );
	scaledTerrainType.SetBias( 0 );
	seaBed.SetSourceModule( 0, scaledSeaTerrain );
	seaBed.SetSourceModule( 1, scaledTerrainType );
	terrainSelector.SetSourceModule( 0, seaBed );
	terrainSelector.SetSourceModule( 1, scaledFlatTerrain );
	terrainSelector.SetControlModule( scaledTerrainType );
	terrainSelector.SetBounds( 0, 1000 );
	terrainSelector.SetEdgeFalloff( 0.125 );
	landTerrainSelector.SetSourceModule( 0, terrainSelector );
	landTerrainSelector.SetSourceModule( 1, scaledMountainTerrain );
	landTerrainSelector.SetControlModule( scaledTerrainType );
	landTerrainSelector.SetBounds( 0.5, 1000 );
	landTerrainSelector.SetEdgeFalloff( 0.125 );
	finalTerrain.SetSourceModule( 0, landTerrainSelector );
	finalTerrain.SetFrequency( 2 );
	finalTerrain.SetPower( 0.0625 );
}
