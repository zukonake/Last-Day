#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <string>
#include <vector>
#include <iostream>
#include <boost/filesystem.hpp>

class FileHandler
{
	std::fstream fileStream;
public:
	std::vector< std::string > getFilesInDirectory( const std::string& directoryPath );

	void openFile( const std::string& filePath, const std::ios_base::openmode& mode );
	void closeFile();

	operator std::iostream& ();
	FileHandler();
};

#endif
