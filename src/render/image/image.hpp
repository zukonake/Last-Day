#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <exception>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

class Image
{
protected:
	SDL_Texture* texture;
	std::string path;

	virtual void load( SDL_Renderer* renderer ) = 0;
public:
	SDL_Texture* getTexture( SDL_Renderer* renderer );
	std::string getPath( void ) const noexcept { return path; }
	void setPath( const std::string& value ) noexcept { path = value; }

	Image( std::istream& in ) noexcept;
	Image( const std::string& path ) noexcept : texture( NULL ), path( path ) { }
	Image( void ) noexcept : texture( NULL ) { }

	virtual ~Image( void ) noexcept;
};

#endif
