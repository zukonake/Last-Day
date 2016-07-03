#include "fileSystemAdapter.hpp"
#include <exception>
#include <iostream>
#include <boost/filesystem.hpp>

FileSystemAdapter::~FileSystemAdapter( void )
{
	close();
}

std::vector< std::string > FileSystemAdapter::getFilesInDirectory( const std::string& directoryPath, const std::string& targetExtension )
{
	std::vector< std::string > output;
	if( boost::filesystem::is_directory( directoryPath ))
	{
		boost::filesystem::directory_iterator endIterator;
		for( boost::filesystem::directory_iterator iterator( directoryPath );
			iterator != endIterator;
			++iterator )
		{
			if( !boost::filesystem::is_directory( iterator->status() ) and iterator->path().extension() == targetExtension )
			{
				output.push_back( iterator->path().string() );
			}
		}
	}
	else
	{
		throw std::runtime_error( "FileSystemAdapter::getFilesInDirectory, Couldn't open directory: " + directoryPath + "." );
		return std::vector< std::string >();
	}
	return output;
}
