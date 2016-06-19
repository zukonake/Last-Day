#ifndef BUILDINGSUBTYPE_HPP
#define BUILDINGSUBTYPE_HPP

#include <entity/entitySubtype.hpp>
#include <geometry/rectangle.hpp>

class BuildingSubtype : protected EntitySubtype
{
	Rectangle shape;
public:
	friend std::istream& operator >> ( std::istream& in, BuildingSubtype& obj );
	friend std::ostream& operator << ( std::ostream& out, const BuildingSubtype& obj );
	BuildingSubtype();
};

#endif
