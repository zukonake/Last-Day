#ifndef BMPIMAGE_HPP
#define BMPIMAGE_HPP

#include <exception>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
//
#include <render/image/image.hpp>

class BMPImage : public Image
{
	virtual void load( SDL_Renderer* renderer ) override;
public:

	BMPImage( std::istream& in ) noexcept : Image( in ) { }
	BMPImage( const std::string& path ) noexcept : Image( path ) { }
	BMPImage( void ) noexcept : Image() { }

	virtual ~BMPImage( void ) noexcept { }
};

#endif
