#include "fileHandler.hpp"

std::vector< std::string > FileHandler::getFilesInDirectory( const std::string& directoryPath )
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

void FileHandler::openFile( const std::string& filePath, std::ios_base::openmode mode )
{
	fileStream.open( filePath, mode );
	if( !fileStream.good() )
	{
		std::cout << "ERROR: Couldn't open file: " << filePath << "\n";
		//TODO throw exception
	}
}

void FileHandler::closeFile()
{
	fileStream.close();
}

FileHandler::operator std::istream&()
{
	return fileStream;
}

FileHandler::FileHandler()
{

}
