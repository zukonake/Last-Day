#ifndef MOBSUBTYPE_HPP
#define MOBSUBTYPE_HPP

#include <iostream>
//
#include <entity/entitySubtype.hpp>

class MobSubtype : public EntitySubtype
{
public:
	explicit MobSubtype( std::istream& in ) noexcept;
	MobSubtype( void ) = default;
};

#endif
