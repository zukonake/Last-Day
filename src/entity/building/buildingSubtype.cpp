#include "buildingSubtype.hpp"

BuildingSubtype::BuildingSubtype( std::istream& in ) :
	EntitySubtype( in ),
	shape( in )
{

}

BuildingSubtype::~BuildingSubtype()
{

}
