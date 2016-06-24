#include "fileSystemAdapter.hpp"

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
		std::cout << "ERROR: Couldn't open directory: " << directoryPath << "\n";
		//TODO throw exception
	}
	return output;
}

FileSystemAdapter::FileSystemAdapter()
{

}

FileSystemAdapter::~FileSystemAdapter()
{
	close();
}
