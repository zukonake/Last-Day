#ifndef BMPIMAGE_HPP
#define BMPIMAGE_HPP

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
//
#include <render/image/image.hpp>

class BMPImage : public Image
{
public:
	BMPImage( std::istream& in ) noexcept : Image( in ) { }
	BMPImage( const std::string& path ) noexcept : Image( path ) { }
	BMPImage( void ) noexcept : Image() { }
private:
	virtual void load( SDL_Renderer* renderer ) override;
};

#endif
