#ifndef FILESYSTEMADAPTER_HPP
#define FILESYSTEMADAPTER_HPP

#include <fstream>
#include <string>
#include <vector>

class FileSystemAdapter : public std::fstream
{
public:
	std::vector< std::string > getFilesInDirectory( const std::string& directoryPath, const std::string& targetExtension = ".ldo" );
	void changeWorkDirectory( const std::string& directoryPath );

	FileSystemAdapter();
	~FileSystemAdapter();
};

#endif
