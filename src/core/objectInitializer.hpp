#ifndef OBJECTINITIALIZER_HPP
#define OBJECTINITIALIZER_HPP

#include <vector>
#include <string>

class ObjectInitializer
{
	const std::string rootFolder = "dataset/";
	std::vector< std::string > listFiles( std::string folderPath );
	std::string loadFile();
public:
	template < typename T > std::vector< T > initializeObjectVector( std::string folderPath );
	ObjectInitializer();
};

#endif
