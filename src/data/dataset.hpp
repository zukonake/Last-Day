#ifndef DATASET_HPP
#define DATASET_HPP

#include <exception>
#include <iostream>
#include <string>
#include <map>
//
#include <data/fileSystemAdapter.hpp>
#include <entity/entitySubtype.hpp>
#include <world/tile/tileSubtype.hpp>
#include <entity/mob/mobSubtype.hpp>
#include <entity/building/buildingSubtype.hpp>

class Dataset
{
	const std::string datasetPath = "dataset/generic/";
public:
	Dataset();

	std::map< const std::string, EntitySubtype > initializedEntitySubtypes;
	std::map< const std::string, TileSubtype > initializedTileSubtypes;
	std::map< const std::string, MobSubtype > initializedMobSubtypes;
	std::map< const std::string, BuildingSubtype > initializedBuildingSubtypes;
private:
	void initializeObjects( void ) noexcept;
	template< typename ObjectType >
	std::map< const std::string, ObjectType > initializeObjectVectorFromDirectory( const std::string& directoryPath );

	FileSystemAdapter fileSystem;
};

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
#endif
