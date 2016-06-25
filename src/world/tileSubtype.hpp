#ifndef TILESUBTYPE_HPP
#define TILESUBTYPE_HPP

#include <string>
#include <iostream>
//
#include <render/image.hpp>

class TileSubtype : public Image
{
	bool isPassable;
public:
	static unsigned int spriteSize;
	std::string name;

	TileSubtype( std::istream& in );
	TileSubtype();
	~TileSubtype();
};

#endif