#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include <iostream>
//
#include <SDL/SDL.h>
#include <render/sprite.hpp>
#include <render/userInterface.hpp>

class Tile : public Sprite
{
	std::string name;
	bool isPassable;
public:
	Tile();
	~Tile();

	friend std::istream& operator >> (std::istream& in, Tile& obj );
	friend std::ostream& operator << (std::ostream& out, const Tile& obj );
};

#endif
