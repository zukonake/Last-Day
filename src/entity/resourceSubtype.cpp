#include "resourceSubtype.hpp"

ResourceSubtype::ResourceSubtype( std::istream& in )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> name;
}

ResourceSubtype::~ResourceSubtype()
{

}
