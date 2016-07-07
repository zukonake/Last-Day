#include "building.hpp"
#include <entity/building/buildingSubtype.hpp>

Building::Building( const Point& position, const BuildingSubtype* subtype, World& world ) noexcept :
	Entity( position, subtype, world )
{

}
