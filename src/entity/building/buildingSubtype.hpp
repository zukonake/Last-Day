#ifndef BUILDINGSUBTYPE_HPP
#define BUILDINGSUBTYPE_HPP

#include <iostream>
//

#include <entity/entitySubtype.hpp>

class BuildingSubtype : public EntitySubtype
{
public:
	explicit BuildingSubtype( std::istream& in ) noexcept;
	BuildingSubtype( void ) = default;
private:
	Point mShape;
};

#endif
