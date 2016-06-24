#ifndef BUILDINGSUBTYPE_HPP
#define BUILDINGSUBTYPE_HPP

#include <iostream>
//
#include <geometry/rectangle.hpp>
#include <entity/entitySubtype.hpp>

class BuildingSubtype : public EntitySubtype, public Rectangle
{
public:
	BuildingSubtype( std::istream& in );
	BuildingSubtype() { }
	~BuildingSubtype();
};

#endif
