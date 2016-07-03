#include "building.hpp"

Building::Building( World& world, const Point& position, BuildingSubtype* subtype ) noexcept :
	Entity( world, position, subtype )
{

}
