#include "dataset.hpp"

Dataset::Dataset()
{
	initializedEntitySubtypes = initializeObjectVectorFromDirectory< EntitySubtype >( "entitySubtype" );
	initializedTileSubtypes = initializeObjectVectorFromDirectory< TileSubtype >( "tile" );
	initializedMobSubtypes = initializeObjectVectorFromDirectory< MobSubtype >( "mobSubtype" );
	initializedBuildingSubtypes = initializeObjectVectorFromDirectory< BuildingSubtype >( "buildingSubtype" );
}
