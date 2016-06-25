#ifndef ENTITYSUBTYPE_HPP
#define ENTITYSUBTYPE_HPP

#include <string>
#include <iostream>
//
#include <render/image.hpp>

class EntitySubtype : public Image
{
public:
	std::string name;

	EntitySubtype( std::istream& in );
	EntitySubtype() { }
	virtual ~EntitySubtype();
};

#endif
