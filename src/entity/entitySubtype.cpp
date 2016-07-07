#include "entitySubtype.hpp"
#include <exception>

EntitySubtype::EntitySubtype( std::istream& in ) noexcept :
Renderable( in )
{
	in.ignore( 255, ' ' );
	in >> mName;
}

const std::string& EntitySubtype::getName( void ) const noexcept
{
	return mName;
}
