#ifndef FILESYSTEMADAPTER_HPP
#define FILESYSTEMADAPTER_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class FileSystemAdapter
{
	std::fstream fileStream;
public:
	std::vector< std::string > getFilesInDirectory( const std::string& directoryPath );
	void changeWorkDirectory( const std::string& directoryPath );
	void openFile( const std::string& filePath, const std::ios_base::openmode& mode );
	void closeFile();

	FileSystemAdapter();
	~FileSystemAdapter();

	operator std::iostream& ();
};

#endif
