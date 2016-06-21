#include "mobSubtype.hpp"

std::istream& operator >> ( std::istream& in, MobSubtype& obj )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> dynamic_cast< EntitySubtype& >( obj );
	return in;
}

std::ostream& operator << ( std::ostream& out, const MobSubtype& obj )
{
	return out;
}

MobSubtype::MobSubtype()
{

}

MobSubtype::~MobSubtype()
{
	
}
