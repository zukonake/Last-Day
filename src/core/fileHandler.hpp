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

	void openFile( const std::string& filePath, std::ios_base::openmode mode );
	void closeFile();

	//friend std::istream& operator << ( std::istream& in, FileHandler& obj );
	//std::istream& operator >> ( std::istream& in );
	operator std::istream&();
	FileHandler();
};

#endif
