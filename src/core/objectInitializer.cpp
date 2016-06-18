#include "objectInitializer.hpp"
#include <dirent.h>

std::vector< std::string > ObjectInitializer::listFiles( std::string directoryPath )
{
	DIR* directory;
	dirent* directoryReader;
	std::vector< std::string > output;
	if ( ( directory = opendir ( "directoryPath" ) ) != NULL)
	{
		while ( ( directoryReader = readdir ( directory ) ) != NULL)
		{
			output.push_back( directoryReader->d_name );
		}
		closedir ( directory );
	}
	else
	{
		//TODO throw couldnt open dir
	}
	return output;
}

std::string ObjectInitializer::loadFile( std::string filePath )
{
	std::string output;
	return output;
}

ObjectInitializer::ObjectInitializer()
{

}
