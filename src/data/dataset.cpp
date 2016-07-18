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
const EntitySubtype& Dataset::getObject( const std::string& key ) const
{
	return mEntitySubtypes.at( key );
}

template<>
const TileSubtype& Dataset::getObject( const std::string& key ) const
{
	return mTileSubtypes.at( key );
}

template<>
const MobSubtype& Dataset::getObject( const std::string& key ) const
{
	return mMobSubtypes.at( key );
}

template<>
const BuildingSubtype& Dataset::getObject( const std::string& key ) const
{
	return mBuildingSubtypes.at( key );
}

template< typename ObjectType >
std::unordered_map< std::string, ObjectType > Dataset::initializeObjectsFromDirectory( const std::string& directoryPath )
{
	std::unordered_map< std::string, ObjectType > output;
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
