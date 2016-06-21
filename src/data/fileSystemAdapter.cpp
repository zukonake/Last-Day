#include "fileSystemAdapter.hpp"
#include <boost/filesystem.hpp>

std::vector< std::string > FileSystemAdapter::getFilesInDirectory( const std::string& directoryPath )
{
	std::vector< std::string > output;
	if( boost::filesystem::is_directory( directoryPath ))
	{
		boost::filesystem::directory_iterator endIterator;
		for( boost::filesystem::directory_iterator iterator( directoryPath );
			iterator != endIterator;
			++iterator )
		{
			if( !boost::filesystem::is_directory( iterator->status() ) )
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

void FileSystemAdapter::changeWorkDirectory( const std::string& directoryPath )
{
	if( boost::filesystem::is_directory( directoryPath ))
	{
		chdir( directoryPath.c_str() );
	}
	else
	{
		std::cout << "ERROR: Couldn't open directory: " << directoryPath << "\n";
		//TODO throw exception
	}
}

void FileSystemAdapter::openFile( const std::string& filePath, const std::ios_base::openmode& mode )
{
	fileStream.open( filePath, mode );
	if( !fileStream.good() )
	{
		std::cout << "ERROR: Couldn't open file: " << filePath << "\n";
		//TODO throw exception
	}
}

void FileSystemAdapter::closeFile()
{
	fileStream.close();
}

FileSystemAdapter::operator std::iostream& ()
{
	return fileStream; //TODO check file mode
}

FileSystemAdapter::FileSystemAdapter()
{

}

FileSystemAdapter::~FileSystemAdapter()
{
	closeFile();
}
