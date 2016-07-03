#include "image.hpp"
#include <exception>

Image::Image( std::istream& in ) noexcept :
	texture( nullptr )
{
	in.ignore( 255, ' ' );
	in >> path;
}

Image::~Image( void ) noexcept
{
	SDL_DestroyTexture( texture );
}

SDL_Texture* Image::getTexture( SDL_Renderer* renderer )
{
	if( texture == nullptr )
	{
		if( renderer == nullptr )
		{
			throw std::invalid_argument( "Image::getTexture, null pointer given in argument 1." );
			return nullptr;
		}
		try
		{
			load( renderer );
		}
		catch( std::exception& e )
		{
			std::cerr << "ERROR: Standard exception: " << e.what() << "\n";
			return nullptr;
		}
	}
	return texture;
}
