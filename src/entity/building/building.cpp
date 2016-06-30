#include "building.hpp"

Building::Building( BuildingSubtype* subtype, const Point& position ) :
	Entity( subtype, position )
{

}

Building::~Building()
{

}
