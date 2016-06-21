#include "dataset.hpp"

void Dataset::initializeObjects()
{
	initializedTiles = initializeObjectVectorFromDirectory< Tile >( "tile" );
	initializedMobSubtypes = initializeObjectVectorFromDirectory< MobSubtype >( "mobSubtype" );
	initializedBuildingSubtypes = initializeObjectVectorFromDirectory< BuildingSubtype >( "buildingSubtype" );
	initializedResourceSubtypes = initializeObjectVectorFromDirectory< ResourceSubtype >( "resourceSubtype" );
}

Dataset::Dataset()
{

}
