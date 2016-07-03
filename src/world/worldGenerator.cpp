#include "worldGenerator.hpp"
#include <cstdint>
#include <cstdlib>
//
#include <entity/entity.hpp>

WorldGenerator::WorldGenerator( Dataset& availableDataset, EntityContainer& entityContainer ) noexcept :
	availableDataset( availableDataset ),
	entityContainer( entityContainer )
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

Chunk& WorldGenerator::generateChunk( World& world, Chunk& target, const Point& targetChunkPosition ) noexcept
{
	for( uint8_t iteratorY = 0; iteratorY < Chunk::sizeInTiles; iteratorY++ )
	{
		for( uint8_t iteratorX = 0; iteratorX < Chunk::sizeInTiles; iteratorX++ )
		{
			Point firstTile = targetChunkPosition.tilePosition( Chunk::sizeInTiles );
			generateTile( world, target.tiles[ iteratorX ][ iteratorY ], Point( firstTile.x + ( int ) iteratorX, firstTile.y + ( int ) iteratorY ) );
		}
	}
	return target;
}

Tile& WorldGenerator::generateTile( World& world, Tile& target, const Point& targetTilePosition ) noexcept
{
	double heightValue = finalTerrain.GetValue( (double)( targetTilePosition.x ) / scale, (double)( targetTilePosition.y ) / scale, 0 );
	if( heightValue >= 0.55 )
	{
		target = Tile( &availableDataset.initializedTileSubtypes[ "stone" ], heightValue*heightMultiplier);
	}
	else if( heightValue >= 0.5 )
	{
		target = Tile( &availableDataset.initializedTileSubtypes[ "dirt" ], heightValue*heightMultiplier);
	}
	else if( heightValue >= -0.1 )
	{
		target = Tile( &availableDataset.initializedTileSubtypes[ "grass" ], heightValue*heightMultiplier);
		if( ( rand() % 10 ) == 1 )
		{
			entityContainer.addEntity( new Entity( world,
				targetTilePosition,
				&availableDataset.initializedEntitySubtypes[ "tree" ] ) );
		}
	}
	else if( heightValue >= -0.2 )
	{
		target = Tile( &availableDataset.initializedTileSubtypes[ "sand" ], heightValue*heightMultiplier);
	}
	else if( heightValue < -0.2 )
	{
		target = Tile( &availableDataset.initializedTileSubtypes[ "water" ], heightValue*heightMultiplier);
	}
	return target;
}
