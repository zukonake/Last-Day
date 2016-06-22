#ifndef BUILDINGSUBTYPE_HPP
#define BUILDINGSUBTYPE_HPP

#include <entity/entitySubtype.hpp>
#include <geometry/rectangle.hpp>

class BuildingSubtype : public EntitySubtype
{
	Rectangle shape;
public:
	BuildingSubtype();
	~BuildingSubtype();

	friend std::istream& operator >> ( std::istream& in, BuildingSubtype& obj );
	friend std::ostream& operator << ( std::ostream& out, const BuildingSubtype& obj );
};

#endif
