#include "dataset.hpp"
#include <iostream>
void Dataset::initializeVectorsFromFiles()
{
	initializedMobSubtypes = initializer.initializeObjectVector< MobSubtype >( "mobSubtype" );
	initializedBuildingSubtypes = initializer.initializeObjectVector< BuildingSubtype >( "buildingSubtype" );
	initializedResourceSubtypes = initializer.initializeObjectVector< ResourceSubtype >( "resourceSubtype" );
}

Dataset::Dataset( FileHandler* fileHandler ) : initializer( ObjectInitializer( fileHandler ))
{

}
