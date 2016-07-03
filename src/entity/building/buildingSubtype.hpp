#ifndef BUILDINGSUBTYPE_HPP
#define BUILDINGSUBTYPE_HPP

#include <iostream>
//
#include <geometry/rectangle.hpp>
#include <entity/entitySubtype.hpp>

class BuildingSubtype : public EntitySubtype
{
public:
	BuildingSubtype( std::istream& in ) noexcept;
private:
	Rectangle shape;
};

#endif
