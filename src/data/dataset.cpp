#include "dataset.hpp"
#include <iostream>
#include <exception>

Dataset::Dataset( void )
{
	initializeObjects();
}

void Dataset::initializeObjects( void ) noexcept
{
	mEntitySubtypes = initializeObjectsFromDirectory< EntitySubtype >( "entitySubtype" );
	mTileSubtypes = initializeObjectsFromDirectory< TileSubtype >( "tileSubtype" );
	mMobSubtypes = initializeObjectsFromDirectory< MobSubtype >( "mobSubtype" );
	mBuildingSubtypes = initializeObjectsFromDirectory< BuildingSubtype >( "buildingSubtype" );
}

template<>
std::shared_ptr< const EntitySubtype > Dataset::getObject( const std::string& key ) const
{
	return std::make_shared< EntitySubtype >( mEntitySubtypes.at( key ) );
}

template<>
std::shared_ptr< const TileSubtype > Dataset::getObject( const std::string& key ) const
{
	return std::make_shared< TileSubtype >( mTileSubtypes.at( key ) );
}

template<>
std::shared_ptr< const MobSubtype > Dataset::getObject( const std::string& key ) const
{
	return std::make_shared< MobSubtype >( mMobSubtypes.at( key ) );
}

template<>
std::shared_ptr< const BuildingSubtype > Dataset::getObject( const std::string& key ) const
{
	return std::make_shared< BuildingSubtype >( mBuildingSubtypes.at( key ) );
}

template< typename ObjectType >
std::map< const std::string, ObjectType > Dataset::initializeObjectsFromDirectory( const std::string& directoryPath )
{
	std::map< const std::string, ObjectType > output;
	try
	{
		for( auto iFile : fileSystem.getFilesInDirectory( cDatasetPath + directoryPath ) )
		{
			fileSystem.open( iFile, std::ios::in );
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
