#include "buildingSubtype.hpp"

BuildingSubtype::BuildingSubtype( std::istream& in ) noexcept :
	EntitySubtype( in ),
	mShape( in )
{

}
