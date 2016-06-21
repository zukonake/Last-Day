#ifndef DATASET_HPP
#define DATASET_HPP

#include <string>
#include <vector>
//
#include <data/fileSystemAdapter.hpp>
#include <world/tile.hpp>
#include <entity/mobSubtype.hpp>
#include <entity/buildingSubtype.hpp>
#include <entity/resourceSubtype.hpp>
#include <world/world.hpp>

class Dataset
{
	const std::string datasetPath = "dataset/generic/";
protected:
	std::vector< Tile > initializedTiles;
	std::vector< MobSubtype > initializedMobSubtypes;
	std::vector< BuildingSubtype > initializedBuildingSubtypes;
	std::vector< ResourceSubtype > initializedResourceSubtypes;
private:
	FileSystemAdapter fileSystem;

	void initializeObjects();
	template< typename ObjectType >
	std::vector< ObjectType > initializeObjectVectorFromDirectory( const std::string& directoryPath );
	template< typename ObjectType >
	ObjectType initializeObjectFromFile( const std::string& filePath );
protected:
	Dataset();
};

template< typename ObjectType >
std::vector< ObjectType > Dataset::initializeObjectVectorFromDirectory( const std::string& directoryPath )
{
	std::vector< ObjectType > output;

	for( auto iterator : fileSystem.getFilesInDirectory( datasetPath + directoryPath ) )
	{
		output.push_back( initializeObjectFromFile< ObjectType > ( iterator ) );
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
