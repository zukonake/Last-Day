#ifndef ENTITYSUBTYPE_HPP
#define ENTITYSUBTYPE_HPP

#include <string>
#include <iostream>
//
#include <render/sprite.hpp>

class EntitySubtype : public Sprite
{
public:
	std::string name;

	EntitySubtype( std::istream& in );
	EntitySubtype() { }
	virtual ~EntitySubtype();
};

#endif
