#ifndef FILESYSTEMADAPTER_HPP
#define FILESYSTEMADAPTER_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class FileSystemAdapter : public std::fstream
{
public:
	std::vector< std::string > getFilesInDirectory( const std::string& directoryPath, const std::string& targetExtension = ".ldo" );
	void changeWorkDirectory( const std::string& directoryPath );

	FileSystemAdapter();
	~FileSystemAdapter();
};

#endif
