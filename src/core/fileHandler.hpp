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
};

#endif
