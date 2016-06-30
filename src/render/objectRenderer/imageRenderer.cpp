#include "imageRenderer.hpp"

void ImageRenderer::renderEntitySubtype( const EntitySubtype* target, const SDL_Rect& targetPosition )
{
	if( images[ target->getImagePath() ] == nullptr )
	{
		images[ target->getImagePath() ] = new PNGImage( target->getImagePath() );
	}
	if( target == nullptr )
	{
		throw std::invalid_argument( "ERROR: ImageRenderer::renderEntitySubtype, null pointer given in argument 1." );
		return;
	}
	SDL_RenderCopy( ObjectRenderer::getRenderer(), images[ target->getImagePath() ]->getTexture( ObjectRenderer::getRenderer() ), nullptr, &targetPosition );
	return;
}

void ImageRenderer::renderTileSubtype( const TileSubtype* target, const SDL_Rect& targetPosition )
{
	if( images[ target->getImagePath() ] == nullptr )
	{
		images[ target->getImagePath() ] = new PNGImage( target->getImagePath() );
	}
	if( target == nullptr )
	{
		throw std::invalid_argument( "ERROR: ImageRenderer::renderTileSubtype, null pointer given in argument 1." );
		return;
	}
	SDL_RenderCopy( ObjectRenderer::getRenderer(), images[ target->getImagePath() ]->getTexture( ObjectRenderer::getRenderer() ), nullptr, &targetPosition );
	return;
}

ImageRenderer::ImageRenderer( SDL_Renderer* renderer ) noexcept :
	ObjectRenderer( renderer )
{

}

ImageRenderer::~ImageRenderer( void ) noexcept
{
	for( auto iterator = images.begin(); iterator != images.end(); iterator++ )
	{
		delete iterator->second;
	}
}
