#ifndef RENDERABLEOBJECT_HPP
#define RENDERABLEOBJECT_HPP

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
//
class ObjectRenderer;

class RenderableObject
{
public:
	RenderableObject( std::istream& in ) noexcept;
	RenderableObject( const std::string& imagePath ) noexcept : imagePath( imagePath ) { }
	RenderableObject( void ) noexcept { }

	const std::string& getImagePath( void ) const noexcept;
private:
	virtual void render( ObjectRenderer* objectRenderer, const SDL_Rect& targetPosition ) const = 0;

	std::string imagePath;
};

#endif
