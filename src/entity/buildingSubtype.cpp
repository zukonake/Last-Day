#include "buildingSubtype.hpp"

std::istream& operator >> ( std::istream& in, BuildingSubtype& obj )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> dynamic_cast< EntitySubtype& >( obj );
	in >> obj.shape;
	return in;
}

std::ostream& operator << ( std::ostream& out, const BuildingSubtype& obj )
{
	return out;
}

BuildingSubtype::BuildingSubtype()
{

}

BuildingSubtype::~BuildingSubtype()
{
	
}
