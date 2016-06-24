#ifndef FILESYSTEMADAPTER_HPP
#define FILESYSTEMADAPTER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>

class FileSystemAdapter : public std::fstream
{
public:
	std::vector< std::string > getFilesInDirectory( const std::string& directoryPath, const std::string& targetExtension = ".ldo" );

	FileSystemAdapter();
	~FileSystemAdapter();
};

#endif
