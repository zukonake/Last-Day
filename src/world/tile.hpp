#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include <iostream>
//
#include <SDL/SDL.h>
#include <render/sprite.hpp>
#include <render/interface.hpp>

class Tile
{
	std::string name;
	bool isPassable;
	Sprite* sprite;
public:
	friend std::istream& operator >> (std::istream& in, Tile& obj );
	friend std::ostream& operator << (std::ostream& out, const Tile& obj );
	void render( Interface* targetInterface, SDL_Rect* targetPosition );
	Tile();
};

#endif
