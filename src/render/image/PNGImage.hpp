#ifndef PNGIMAGE_HPP
#define PNGIMAGE_HPP

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
//
#include <render/image/image.hpp>

class PNGImage : public Image
{
public:
	PNGImage( std::istream& in ) noexcept : Image( in ) { }
	PNGImage( const std::string& path ) noexcept : Image( path ) { }
	PNGImage( void ) noexcept : Image() { }
private:
	virtual void load( SDL_Renderer* renderer ) override;
};

#endif
