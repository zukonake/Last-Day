#ifndef OBJECTINITIALIZER_HPP
#define OBJECTINITIALIZER_HPP

#include <vector>
#include <string>

class ObjectInitializer
{
	const std::string datasetDirectory = "dataset/";
	std::vector< std::string > listFiles( std::string directoryPath );
	std::string loadFile( std::string filePath );
public:
	template < typename objectType >
	std::vector< objectType > initializeObjectVector( std::string directoryPath );
	ObjectInitializer();
};

template < typename objectType >
std::vector< objectType > ObjectInitializer::initializeObjectVector( std::string directoryPath )
{
	std::vector< objectType > output;
	return output;
}

#endif
