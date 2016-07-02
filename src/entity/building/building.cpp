#include "building.hpp"

Building::Building( BuildingSubtype* subtype, World& world, const Point& position ) :
	Entity( subtype, world, position )
{

}

Building::~Building()
{

}
