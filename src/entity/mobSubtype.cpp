#include "mobSubtype.hpp"

MobSubtype::MobSubtype( std::istream& in ) :
	EntitySubtype( in )
{
	const unsigned int maximumVariableLength = 256;
	std::cout << "INFO: Initializing mobSubtype: " << name << " .\n";
}

MobSubtype::~MobSubtype()
{

}
