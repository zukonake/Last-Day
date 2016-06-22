#ifndef DATASET_HPP
#define DATASET_HPP

#include <string>
#include <map>
//
#include <data/fileSystemAdapter.hpp>
#include <world/tile.hpp>
#include <entity/mobSubtype.hpp>
#include <entity/buildingSubtype.hpp>
#include <entity/resourceSubtype.hpp>

class Dataset
{
	const std::string datasetPath = "dataset/generic/";
protected:
	std::map< const std::string, Tile > initializedTiles;
	std::map< const std::string, MobSubtype > initializedMobSubtypes;
	std::map< const std::string, BuildingSubtype > initializedBuildingSubtypes;
	std::map< const std::string, ResourceSubtype > initializedResourceSubtypes;
private:
	FileSystemAdapter fileSystem;

	void initializeObjects();
	template< typename ObjectType >
	std::map< const std::string, ObjectType > initializeObjectVectorFromDirectory( const std::string& directoryPath );
	template< typename ObjectType >
	ObjectType initializeObjectFromFile( const std::string& filePath );
protected:
	Dataset();
};

template< typename ObjectType >
std::map< const std::string, ObjectType > Dataset::initializeObjectVectorFromDirectory( const std::string& directoryPath )
{
	std::map< const std::string, ObjectType > output;

	for( auto iterator : fileSystem.getFilesInDirectory( datasetPath + directoryPath ) )
	{
		ObjectType objectOutput = initializeObjectFromFile< ObjectType > ( iterator );
		output[ objectOutput.name ] = objectOutput;
	}

	return output;
}

template< typename ObjectType >
ObjectType Dataset::initializeObjectFromFile( const std::string& filePath )
{
	ObjectType output;

	fileSystem.openFile( filePath, std::ios::in );
	fileSystem >> output;
	fileSystem.closeFile();

	return output;
}

#endif
