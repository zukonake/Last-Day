#include "mobSubtype.hpp"

std::istream& operator >> ( std::istream& in, MobSubtype& obj )
{
	return in;
}

std::ostream& operator << ( std::ostream& out, const MobSubtype& obj )
{
	return out;
}

MobSubtype::MobSubtype()
{

}
