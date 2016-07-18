#ifndef DATASET_HPP
#define DATASET_HPP

#include <memory>
#include <string>
#include <unordered_map>
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
	const ObjectType& getObject( const std::string& key ) const;
private:
	void initializeObjects( void ) noexcept;
	template< typename ObjectType >
	std::unordered_map< std::string, ObjectType > initializeObjectsFromDirectory( const std::string& directoryPath );

	std::unordered_map< std::string, EntitySubtype > mEntitySubtypes;
	std::unordered_map< std::string, TileSubtype > mTileSubtypes;
	std::unordered_map< std::string, MobSubtype > mMobSubtypes;
	std::unordered_map< std::string, BuildingSubtype > mBuildingSubtypes;

	FileSystemAdapter fileSystem;
};

#endif
