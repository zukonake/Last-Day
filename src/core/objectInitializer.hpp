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
public:
	template < typename ObjectType >
	std::vector< ObjectType > initializeObjectVector( FileHandler& fileHandler, const std::string& directoryPath );

	ObjectInitializer();
};

template < typename ObjectType >
std::vector< ObjectType > ObjectInitializer::initializeObjectVector( FileHandler& fileHandler, const std::string& directoryPath )
{
	std::vector< ObjectType > output;
	for( auto iterator : fileHandler.getFilesInDirectory( "dataset/generic/" + directoryPath ) )
	{
		fileHandler.openFile( iterator, std::ios::in );
		output.push_back( ObjectType() );
		fileHandler >> output.back();
		fileHandler.closeFile();
	}
	return output;
}

#endif
