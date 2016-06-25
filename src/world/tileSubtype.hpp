#ifndef TILESUBTYPE_HPP
#define TILESUBTYPE_HPP

#include <string>
#include <iostream>
//
#include <render/sprite.hpp>

class TileSubtype : public Sprite
{
	bool isPassable;
public:
	static const unsigned int spriteSize = 32;
	std::string name;

	TileSubtype( std::istream& in );
	TileSubtype();
	~TileSubtype();
};

#endif
