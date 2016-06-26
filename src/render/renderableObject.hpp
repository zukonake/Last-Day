#ifndef RENDERABLEOBJECT_HPP
#define RENDERABLEOBJECT_HPP

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>
#include <render/objectRenderer/objectRenderer.hpp>

class RenderableObject
{
	std::string imagePath;
protected:
	virtual void render( ObjectRenderer* objectRenderer, const SDL_Rect& targetPosition ) const = 0;
public:
	std::string getImagePath( void ) const noexcept { return imagePath; }

	RenderableObject( std::istream& in ) noexcept;
	RenderableObject( const std::string& imagePath ) noexcept : imagePath( imagePath ) { }
	RenderableObject( void ) noexcept { }
};

#endif
