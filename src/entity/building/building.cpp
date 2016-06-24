#include "building.hpp"

Building::Building( const Point& position, World& world, const BuildingSubtype& subtype ) :
	Entity( position, world, subtype )
{

}

Building::~Building()
{

}
