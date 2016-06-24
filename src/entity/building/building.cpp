#include "building.hpp"

Building::Building( const Point& position, World& world, std::shared_ptr < BuildingSubtype > subtype ) :
	Entity( position, world, subtype )
{

}

Building::~Building()
{

}
