#include "buildingSubtype.hpp"

BuildingSubtype::BuildingSubtype( std::istream& in ) :
	EntitySubtype( in ),
	Rectangle( in )
{
	const unsigned int maximumVariableLength = 256;
	std::cout << "INFO: Initializing buildingSubtype: " << name << " .\n";
}

BuildingSubtype::~BuildingSubtype()
{

}
