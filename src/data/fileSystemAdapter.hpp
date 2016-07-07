#ifndef FILESYSTEMADAPTER_HPP
#define FILESYSTEMADAPTER_HPP

#include <fstream>
#include <string>
#include <vector>
//
#include <nonCopyable.hpp>

struct FileSystemAdapter : std::fstream, NonCopyable
{
	FileSystemAdapter( void ) noexcept { }

	~FileSystemAdapter( void );

	std::vector< std::string > getFilesInDirectory( const std::string& directoryPath, const std::string& targetExtension = ".ldo" );
};

#endif
