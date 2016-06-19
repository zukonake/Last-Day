#ifndef OBJECTINITIALIZER_HPP
#define OBJECTINITIALIZER_HPP

#include <iostream>
#include <vector>
#include <string>
//
#include <core/fileHandler.hpp>

class ObjectInitializer
{
	const std::string datasetDirectory = "dataset/";
	FileHandler* fileHandler;
public:
	template < typename objectType >
	std::vector< objectType > initializeObjectVector( std::string directoryPath );
	ObjectInitializer( FileHandler* fileHandler );
};

template < typename objectType >
std::vector< objectType > ObjectInitializer::initializeObjectVector( std::string directoryPath )
{
	std::vector< objectType > output;
	for( auto iterator : fileHandler->listFilesInDirectory( "dataset/generic/" ) )
	{
		std::cout << fileHandler->loadFileIntoString( iterator ) << "\n";
	}
	std::cout << "\n";
	return output;
}

#endif
