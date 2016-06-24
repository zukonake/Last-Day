#include "image.hpp"

void Image::render( SDL_Renderer* targetRenderer, SDL_Rect& sourcePosition, SDL_Rect& targetPosition )
{
	if( texture == NULL )
	{
		initialize( targetRenderer );
	}
	SDL_RenderCopy( targetRenderer, texture, &sourcePosition, &targetPosition );
}

void Image::initialize( SDL_Renderer* targetRenderer )
{
	std::cout << "INFO: Initializing image: "<< imagePath << " .\n";
	texture = SDL_CreateTextureFromSurface( targetRenderer, IMG_Load( std::string( imagePath ).c_str() ) );
	if( texture == NULL )
	{
		//TODO throw exception
		std::cout << "ERROR: Couldn't load image: "<< imagePath << " .\n";
	}
}

Image::Image( std::istream& in ) : texture( NULL )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> imagePath;
}

Image::Image() : texture( NULL )
{

}

Image::~Image()
{
	if( texture != NULL )
	{
		std::cout << "INFO: Image destructor called\n";
		SDL_DestroyTexture( texture );
	}
}
