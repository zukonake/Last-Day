#ifndef TILESUBTYPE_HPP
#define TILESUBTYPE_HPP

#include <exception>
#include <string>
#include <iostream>
//
#include <render/objectRenderer/objectRenderer.hpp>
#include <render/renderableObject.hpp>

class TileSubtype : public RenderableObject
{
	static unsigned int spriteSize;

	bool isPassable;
	std::string name;
public:
	static void setSpriteSize( unsigned int value ) noexcept { spriteSize = value; }
	static unsigned int getSpriteSize() noexcept { return spriteSize; }
	const std::string& getName( void ) const noexcept { return name; }

	virtual void render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const override;

	TileSubtype( std::istream& in ) noexcept;
	TileSubtype( void ) noexcept { };
};

#endif
