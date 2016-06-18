#ifndef ENTITYSUBTYPE_HPP
#define ENTITYSUBTYPE_HPP

#include <string>
//
#include <render/sprite.hpp>

class EntitySubtype
{
protected:
	std::string name;
	Sprite* sprite;
private:
	EntitySubtype();
};

#endif
