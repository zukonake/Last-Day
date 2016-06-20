#ifndef MOBSUBTYPE_HPP
#define MOBSUBTYPE_HPP

#include <iostream>
//
#include <entity/entitySubtype.hpp>

class MobSubtype : protected EntitySubtype
{
public:
	MobSubtype();

	friend std::istream& operator >> ( std::istream& in, MobSubtype& obj );
	friend std::ostream& operator << ( std::ostream& out, const MobSubtype& obj );
};

#endif
