#ifndef BUILDINGSUBTYPE_HPP
#define BUILDINGSUBTYPE_HPP

#include <iostream>
//
#include <geometry/rectangle.hpp>
#include <entity/entitySubtype.hpp>

class BuildingSubtype : public EntitySubtype
{
	Rectangle shape;
public:
	BuildingSubtype( std::istream& in );
	BuildingSubtype() { }
	~BuildingSubtype();
};

#endif
