#ifndef TILESUBTYPE_HPP
#define TILESUBTYPE_HPP

#include <cstdint>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
//
#include <render/objectRenderer/objectRenderer.hpp>
#include <render/renderableObject.hpp>

class TileSubtype : public RenderableObject
{
	static uint8_t spriteSize;
public:
	TileSubtype( std::istream& in ) noexcept;
	TileSubtype( void ) noexcept { };

	virtual void render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const override;

	const std::string& getName( void ) const noexcept;
private:
	bool isPassable;
	std::string name;
};

#endif
