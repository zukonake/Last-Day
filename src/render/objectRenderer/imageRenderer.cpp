#include "imageRenderer.hpp"

void ImageRenderer::renderEntitySubtype( const EntitySubtype* target, const SDL_Rect& targetPosition )
{
	if( images[ target->getImagePath() ] == NULL )
	{
		images[ target->getImagePath() ] = new PNGImage( target->getImagePath() );
	}
	if( target == NULL )
	{
		throw std::invalid_argument( "ERROR: ImageRenderer::renderEntitySubtype, null pointer given in argument 1." );
		return;
	}
	SDL_RenderCopy( ObjectRenderer::getRenderer(),images[ target->getImagePath() ]->getTexture( ObjectRenderer::getRenderer() ), NULL, &targetPosition );
	return;
}

void ImageRenderer::renderTileSubtype( const TileSubtype* target, const SDL_Rect& targetPosition )
{
	if( images[ target->getImagePath() ] == NULL )
	{
		images[ target->getImagePath() ] = new PNGImage( target->getImagePath() );
	}
	if( target == NULL )
	{
		throw std::invalid_argument( "ERROR: ImageRenderer::renderTileSubtype, null pointer given in argument 1." );
		return;
	}
	SDL_RenderCopy( ObjectRenderer::getRenderer(), images[ target->getImagePath() ]->getTexture( ObjectRenderer::getRenderer()  ), NULL, &targetPosition );
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
