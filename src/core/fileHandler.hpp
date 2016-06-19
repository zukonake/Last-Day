#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <string>
#include <vector>
#include <boost/filesystem.hpp>

class FileHandler
{
public:
	std::vector< std::string > listFilesInDirectory( boost::filesystem::path directoryPath );
	std::string loadFileIntoString( boost::filesystem::path filePath );
	template < typename objectType >
	objectType loadFileIntoObject( boost::filesystem::path filePath );
};


template < typename objectType >
objectType FileHandler::loadFileIntoObject( boost::filesystem::path filePath )
{
	objectType output;
	boost::filesystem::ifstream fileStream;
	fileStream.open( filePath, std::ios::in );
	if( !fileStream )
	{
		//TODO throw exception
	}

	fileStream >> output;
	return output;
}

#endif
