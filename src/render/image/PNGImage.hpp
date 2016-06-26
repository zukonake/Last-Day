#ifndef PNGIMAGE_HPP
#define PNGIMAGE_HPP

#include <exception>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//
#include <render/image/image.hpp>

class PNGImage : public Image
{
	virtual void load( SDL_Renderer* renderer ) override;
public:

	PNGImage( std::istream& in ) noexcept : Image( in ) { }
	PNGImage( const std::string& path ) noexcept : Image( path ) { }
	PNGImage( void ) noexcept : Image() { }
};

#endif
