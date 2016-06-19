#ifndef OBJECTINITIALIZER_HPP
#define OBJECTINITIALIZER_HPP

#include <iostream>
#include <vector>
#include <string>
//
#include <core/fileHandler.hpp>
#include <entity/entitySubtype.hpp>
#include <entity/mobSubtype.hpp>
#include <entity/buildingSubtype.hpp>
#include <world/resourceSubtype.hpp>

class ObjectInitializer
{
	const std::string datasetDirectory = "dataset/";
	FileHandler* fileHandler;
public:
	template < typename ObjectType >
	std::vector< ObjectType > initializeObjectVector( std::string directoryPath );
	ObjectInitializer( FileHandler* fileHandler );
};

template < typename ObjectType >
std::vector< ObjectType > ObjectInitializer::initializeObjectVector( std::string directoryPath )
{
	std::vector< ObjectType > output;
	for( auto iterator : fileHandler->listFilesInDirectory( "dataset/generic/" + directoryPath ) )
	{
		output.push_back( fileHandler->loadFileIntoObject< ObjectType >( iterator ) );
	}
	return output;
}

#endif
