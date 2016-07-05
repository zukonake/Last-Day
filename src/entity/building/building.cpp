#include "building.hpp"
#include <entity/building/buildingSubtype.hpp>

Building::Building( World& world, const Point& position, BuildingSubtype* subtype ) noexcept :
	Entity( world, position, subtype )
{

}
