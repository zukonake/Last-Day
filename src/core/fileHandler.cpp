#include "fileHandler.hpp"
#include <sstream>

std::vector< std::string > FileHandler::listFilesInDirectory( boost::filesystem::path directoryPath )
{
	std::vector< std::string > output;
	if( boost::filesystem::is_directory( directoryPath ))
	{
		boost::filesystem::directory_iterator endIterator;
		for( boost::filesystem::directory_iterator iterator( directoryPath );
			iterator != endIterator;
			++iterator )
		{
			if( !boost::filesystem::is_directory( iterator->status() ) )
			{
				output.push_back( iterator->path().string() );
			}
		}
	}
	else
	{
		//TODO throw exception
	}
	return output;
}

std::string FileHandler::loadFileIntoString( boost::filesystem::path filePath )
{
	std::stringstream stringStream;
	boost::filesystem::ifstream fileStream;

	fileStream.open( filePath, std::ios::in );
	if( !fileStream )
	{
		//TODO throw exception
		return NULL;
	}
	stringStream << fileStream.rdbuf();
	return stringStream.str();
}
