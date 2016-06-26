#ifndef ENTITYSUBTYPE_HPP
#define ENTITYSUBTYPE_HPP

#include <exception>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
//
#include <render/objectRenderer/objectRenderer.hpp>
#include <render/renderableObject.hpp>

class EntitySubtype : public RenderableObject
{
	std::string name;
public:
	virtual void render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const override;

	EntitySubtype( std::istream& in ) noexcept;
	EntitySubtype( void ) noexcept { };
};

#endif
