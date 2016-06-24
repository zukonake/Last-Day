#include "dataset.hpp"

Dataset::Dataset()
{
	initializedTiles = initializeObjectVectorFromDirectory< Tile >( "tile" );
	initializedMobSubtypes = initializeObjectVectorFromDirectory< MobSubtype >( "mobSubtype" );
	initializedBuildingSubtypes = initializeObjectVectorFromDirectory< BuildingSubtype >( "buildingSubtype" );
}
