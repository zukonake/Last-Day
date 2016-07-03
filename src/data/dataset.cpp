#include "dataset.hpp"

Dataset::Dataset()
{
	initializeObjects();
}

void Dataset::initializeObjects( void ) noexcept
{
	initializedEntitySubtypes = initializeObjectVectorFromDirectory< EntitySubtype >( "entitySubtype" );
	initializedTileSubtypes = initializeObjectVectorFromDirectory< TileSubtype >( "tile" );
	initializedMobSubtypes = initializeObjectVectorFromDirectory< MobSubtype >( "mobSubtype" );
	initializedBuildingSubtypes = initializeObjectVectorFromDirectory< BuildingSubtype >( "buildingSubtype" );
}
