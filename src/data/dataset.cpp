#include "dataset.hpp"
#include <exception>

Dataset::Dataset( void )
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

template<>
const EntitySubtype& Dataset::getObject( const std::string& key ) const
{
	return initializedEntitySubtypes.at( key );
}

template<>
const TileSubtype& Dataset::getObject( const std::string& key ) const
{
	return initializedTileSubtypes.at( key );
}

template<>
const MobSubtype& Dataset::getObject( const std::string& key ) const
{
	return initializedMobSubtypes.at( key );
}

template<>
const BuildingSubtype& Dataset::getObject( const std::string& key ) const
{
	return initializedBuildingSubtypes.at( key );
}

template< typename ObjectType >
std::map< const std::string, ObjectType > Dataset::initializeObjectVectorFromDirectory( const std::string& directoryPath )
{
	std::map< const std::string, ObjectType > output;
	try
	{
		for( auto iterator : fileSystem.getFilesInDirectory( datasetPath + directoryPath ) )
		{
			fileSystem.open( iterator, std::ios::in );
			std::string name;
			fileSystem >> name;
			std::cout << "INFO: Adding object: " << name << ".\n";
			output.emplace( name, fileSystem );
			fileSystem.close();
		}
	}
	catch( std::exception& e)
	{
		std::cerr << "ERROR: Standard exception: " << e.what() << ".\n";
	}
	return output;
}
