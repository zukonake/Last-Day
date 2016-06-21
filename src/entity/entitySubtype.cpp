#include "entitySubtype.hpp"

std::istream& operator >> ( std::istream& in, EntitySubtype& obj )
{
	const unsigned int maximumVariableLength = 256;
	in >> obj.name;
	in >> dynamic_cast< Sprite& >( obj );
	return in;
}

std::ostream& operator << ( std::ostream& out, const EntitySubtype& obj )
{
	return out;
}

EntitySubtype::EntitySubtype() : Sprite()
{

}

EntitySubtype::~EntitySubtype()
{

}
