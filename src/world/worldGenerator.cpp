#include "worldGenerator.hpp"
#include <cstdint>
#include <cstdlib>
//
#include <entity/entity.hpp>
#include <entity/mob/mob.hpp>
#include <entity/building/building.hpp>
#include <data/dataset.hpp>
#include <world/chunk/chunk.hpp>
#include <world/world.hpp>

WorldGenerator::WorldGenerator( World& world, const Dataset& dataset, const int& seed ) noexcept :
	mWorld( world ),
	mDataset( dataset ),
	mSeed( seed )
{
	flatTerrain.SetSeed( mSeed );
	flatTerrain.SetFrequency( 0.25 );

	mountainTerrain.SetSeed( mSeed );
	mountainTerrain.SetFrequency( 0.5 );

	terrainType.SetSeed( mSeed );
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

	finalTerrain.SetSeed( mSeed );
	finalTerrain.SetSourceModule( 0, landTerrainSelector );
	finalTerrain.SetFrequency( 2 );
	finalTerrain.SetPower( 0.0625 );
}

Chunk& WorldGenerator::generateChunk( const Point& targetChunkPosition, Chunk& target ) const noexcept
{
	for( uint16_t iteratorY = 0; iteratorY < Chunk::sizeInTiles; iteratorY++ )
	{
		for( uint16_t iteratorX = 0; iteratorX < Chunk::sizeInTiles; iteratorX++ )
		{
			Point firstTile = Point::tilePosition( targetChunkPosition, Chunk::sizeInTiles );
			Point targetTilePosition = { firstTile.x + ( int ) iteratorX, firstTile.y + ( int ) iteratorY };
			generateTile( targetTilePosition, target.value[ iteratorX ][ iteratorY ] );
		}
	}
	return target;
}

Tile& WorldGenerator::generateTile( const Point& targetTilePosition, Tile& target ) const noexcept
{
	double heightValue = finalTerrain.GetValue( (double)( targetTilePosition.x ) / csScale, (double)( targetTilePosition.y ) / csScale, 0 );
	if( heightValue >= 0.6 )
	{
		target = Tile( &mDataset.getObject< TileSubtype >( "stone" ), heightValue * csHeightMultiplier);
	}
	else if( heightValue >= 0.5 )
	{
		target = Tile( &mDataset.getObject< TileSubtype >( "dirt" ), heightValue * csHeightMultiplier);
	}
	else if( heightValue >= -0.05 )
	{
		target = Tile( &mDataset.getObject< TileSubtype >( "grass" ), heightValue * csHeightMultiplier);
		if( heightValue >= 0 and heightValue <= 0.45  and ( rand() % 10 ) == 1 )
		{
			mWorld.addEntity< Entity >( targetTilePosition,
				&mDataset.getObject< EntitySubtype >( "tree" ),
				mWorld );
		}
	}
	else if( heightValue >= -0.2 )
	{
		target = Tile( &mDataset.getObject< TileSubtype >(  "sand" ), heightValue * csHeightMultiplier);
	}
	else if( heightValue < -0.2 )
	{
		target = Tile( &mDataset.getObject< TileSubtype >( "water" ), heightValue * csHeightMultiplier);
	}
	return target;
}

const int& WorldGenerator::getSeed( void ) const noexcept
{
	return mSeed;
}
