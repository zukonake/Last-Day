#ifndef DATASET_HPP
#define DATASET_HPP

#include <iostream>
#include <string>
#include <map>
//
#include <data/fileSystemAdapter.hpp>
#include <entity/entitySubtype.hpp>
#include <world/tileSubtype.hpp>
#include <entity/mob/mobSubtype.hpp>
#include <entity/building/buildingSubtype.hpp>

class Dataset
{
	friend class WorldGenerator;
	friend class World;
	const std::string datasetPath = "dataset/generic/";
protected:
	std::map< const std::string, EntitySubtype > initializedEntitySubtypes;
	std::map< const std::string, TileSubtype > initializedTileSubtypes;
	std::map< const std::string, MobSubtype > initializedMobSubtypes;
	std::map< const std::string, BuildingSubtype > initializedBuildingSubtypes;
private:
	FileSystemAdapter fileSystem;

	void initializeObjects();
	template< typename ObjectType >
	std::map< const std::string, ObjectType > initializeObjectVectorFromDirectory( const std::string& directoryPath );
public:
	Dataset();
};

template< typename ObjectType >
std::map< const std::string, ObjectType > Dataset::initializeObjectVectorFromDirectory( const std::string& directoryPath )
{
	std::map< const std::string, ObjectType > output;

	for( auto iterator : fileSystem.getFilesInDirectory( datasetPath + directoryPath ) )
	{
		fileSystem.open( iterator, std::ios::in );
		std::string name;
		fileSystem >> name;
		std::cout << "INFO: Adding object: " << name << ".\n";
		output.emplace( name, fileSystem );
		fileSystem.close();
	}

	return output;
}
#endif
