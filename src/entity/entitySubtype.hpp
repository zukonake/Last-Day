#ifndef ENTITYSUBTYPE_HPP
#define ENTITYSUBTYPE_HPP

#include <string>
#include <iostream>
//
#include <render/sprite.hpp>

class EntitySubtype : public Sprite
{
protected:
	std::string name;
public:
	EntitySubtype();
	virtual ~EntitySubtype();

	friend std::istream& operator >> ( std::istream& in, EntitySubtype& obj );
	friend std::ostream& operator << ( std::ostream& out, const EntitySubtype& obj );
};

#endif
