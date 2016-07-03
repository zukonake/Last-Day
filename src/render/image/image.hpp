#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

class Image
{
public:
	Image( std::istream& in ) noexcept;
	Image( const std::string& path ) noexcept : path( path ), texture( nullptr ) { }
	Image( const Image& that ) = delete;
	Image( void ) noexcept : texture( nullptr ) { }

	virtual ~Image( void ) noexcept;

	Image& operator=( const Image& that ) = delete;

	SDL_Texture* getTexture( SDL_Renderer* renderer );

	const std::string& getPath( void ) const noexcept { return path; }
	void setPath( const std::string& value ) noexcept { path = value; }
protected:
	std::string path;
	SDL_Texture* texture;
private:
	virtual void load( SDL_Renderer* renderer ) = 0;
};

#endif
