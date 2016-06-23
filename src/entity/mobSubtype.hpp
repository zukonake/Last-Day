#ifndef MOBSUBTYPE_HPP
#define MOBSUBTYPE_HPP

#include <iostream>
//
#include <entity/entitySubtype.hpp>

class MobSubtype : public EntitySubtype
{
public:
	MobSubtype( std::istream& in );
	MobSubtype() { }
	~MobSubtype();
};

#endif
