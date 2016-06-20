#include "dataset.hpp"
#include <iostream>
void Dataset::initializeVectorsFromFiles( FileHandler& fileHandler )
{
	initializedMobSubtypes = initializer.initializeObjectVector< MobSubtype >( fileHandler, "mobSubtype" );
	initializedBuildingSubtypes = initializer.initializeObjectVector< BuildingSubtype >( fileHandler, "buildingSubtype" );
	initializedResourceSubtypes = initializer.initializeObjectVector< ResourceSubtype >( fileHandler, "resourceSubtype" );
	initializedTiles = initializer.initializeObjectVector< Tile >( fileHandler, "tile" );
}

Dataset::Dataset()
{

}
