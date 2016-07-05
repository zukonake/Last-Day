#include "building.hpp"
#include <entity/building/buildingSubtype.hpp>

Building::Building( World& world, const Point& position, const BuildingSubtype* subtype ) noexcept :
	Entity( world, position, subtype )
{

}
