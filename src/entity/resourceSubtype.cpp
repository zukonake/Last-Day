#include "resourceSubtype.hpp"

std::istream& operator >> ( std::istream& in, ResourceSubtype& obj )
{
	return in;
}

std::ostream& operator << ( std::ostream& out, const ResourceSubtype& obj )
{
	return out;
}

ResourceSubtype::ResourceSubtype()
{

}

ResourceSubtype::~ResourceSubtype()
{

}
