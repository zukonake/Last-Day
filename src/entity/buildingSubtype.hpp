#ifndef BUILDINGSUBTYPE_HPP
#define BUILDINGSUBTYPE_HPP

#include <entity/entitySubtype.hpp>
#include <geometry/rectangle.hpp>

class BuildingSubtype : public EntitySubtype, public Rectangle
{
public:
	BuildingSubtype( std::istream& in );
	BuildingSubtype() { }
	~BuildingSubtype();
};

#endif
