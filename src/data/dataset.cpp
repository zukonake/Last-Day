#include "dataset.hpp"

Dataset::Dataset()
{
	initializedTileSubtypes = initializeObjectVectorFromDirectory< TileSubtype >( "tile" );
	initializedMobSubtypes = initializeObjectVectorFromDirectory< MobSubtype >( "mobSubtype" );
	initializedBuildingSubtypes = initializeObjectVectorFromDirectory< BuildingSubtype >( "buildingSubtype" );
}
