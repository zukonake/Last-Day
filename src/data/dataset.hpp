#ifndef DATASET_HPP
#define DATASET_HPP

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
	Dataset( void );

	template< typename ObjectType >
	const ObjectType& getObject( const std::string& key ) const;
private:
	void initializeObjects( void ) noexcept;
	template< typename ObjectType >
	std::map< const std::string, ObjectType > initializeObjectVectorFromDirectory( const std::string& directoryPath );

	std::map< const std::string, EntitySubtype > initializedEntitySubtypes;
	std::map< const std::string, TileSubtype > initializedTileSubtypes;
	std::map< const std::string, MobSubtype > initializedMobSubtypes;
	std::map< const std::string, BuildingSubtype > initializedBuildingSubtypes;

	FileSystemAdapter fileSystem;
};

#endif
