#ifndef ENTITYSUBTYPE_HPP
#define ENTITYSUBTYPE_HPP

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
//
#include <render/objectRenderer/objectRenderer.hpp>
#include <render/renderableObject.hpp>

class EntitySubtype : public RenderableObject
{
public:
	EntitySubtype( std::istream& in ) noexcept;
	EntitySubtype( void ) noexcept { };

	virtual void render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const override;

	const std::string& getName( void ) const noexcept;
private:
	std::string name;
};

#endif
