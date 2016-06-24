#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include <iostream>
//
#include <render/sprite.hpp>

class Tile : public Sprite
{
	bool isPassable;
public:
	static const unsigned int spriteSize = 32;
	std::string name;

	Tile( std::istream& in );
	Tile();
	~Tile();
};

#endif
