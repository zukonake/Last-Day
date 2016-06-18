#ifndef BUILDINGSUBTYPE_HPP
#define BUILDINGSUBTYPE_HPP

#include <entity/entitySubtype.hpp>
#include <geometry/rectangle.hpp>

class BuildingSubtype : protected EntitySubtype
{
	Rectangle shape;
};

#endif
