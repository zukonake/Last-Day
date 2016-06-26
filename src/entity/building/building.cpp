#include "building.hpp"

Building::Building( BuildingSubtype* subtype, const Point& position, World& world ) :
	Entity( subtype, position, world )
{

}

Building::~Building()
{

}
