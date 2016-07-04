#ifndef FILESYSTEMADAPTER_HPP
#define FILESYSTEMADAPTER_HPP

#include <fstream>
#include <string>
#include <vector>

struct FileSystemAdapter : std::fstream
{
	FileSystemAdapter( const FileSystemAdapter& that ) = delete;
	FileSystemAdapter( void ) noexcept { }

	~FileSystemAdapter( void );

	FileSystemAdapter& operator=( const FileSystemAdapter& that ) = delete;

	std::vector< std::string > getFilesInDirectory( const std::string& directoryPath, const std::string& targetExtension = ".ldo" );
};

#endif
