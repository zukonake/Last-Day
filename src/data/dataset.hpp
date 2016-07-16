#ifndef DATASET_HPP
#define DATASET_HPP

#include <memory>
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
	const std::string cDatasetPath = "dataset/generic/";
public:
	Dataset( void );

	template< typename ObjectType >
	std::shared_ptr< const ObjectType > getObject( const std::string& key ) const;
private:
	void initializeObjects( void ) noexcept;
	template< typename ObjectType >
	std::map< const std::string, ObjectType > initializeObjectsFromDirectory( const std::string& directoryPath );

	std::map< const std::string, EntitySubtype > mEntitySubtypes;
	std::map< const std::string, TileSubtype > mTileSubtypes;
	std::map< const std::string, MobSubtype > mMobSubtypes;
	std::map< const std::string, BuildingSubtype > mBuildingSubtypes;

	FileSystemAdapter fileSystem;
};

#endif
