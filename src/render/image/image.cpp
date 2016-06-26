#include "image.hpp"

SDL_Texture* Image::getTexture( SDL_Renderer* renderer )
{
	if( texture == NULL )
	{
		if( renderer == NULL )
		{
			throw std::invalid_argument( "ERROR: Image::getTexture, null pointer given in argument 1." );
			return NULL;
		}
		try
		{
			load( renderer );
		}
		catch( std::exception& e )
		{
			std::cerr << "ERROR: Standard exception: " << e.what() << "\n";
			return NULL;
		}
	}
	return texture;
}

Image::Image( std::istream& in ) noexcept :
	texture( NULL )
{
	in.ignore( 255, ' ' );
	in >> path;
}

Image::~Image( void ) noexcept
{
	SDL_DestroyTexture( texture );
}
