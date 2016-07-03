#ifndef IMAGERENDERER_HPP
#define IMAGERENDERER_HPP

#include <string>
#include <map>
#include <SDL2/SDL.h>
//
#include <render/objectRenderer/objectRenderer.hpp>
#include <render/image/image.hpp>
#include <render/image/PNGImage.hpp>
#include <world/tile/tileSubtype.hpp>
#include <entity/entitySubtype.hpp>

class ImageRenderer : public ObjectRenderer
{
public:
	ImageRenderer( SDL_Renderer* renderer ) noexcept : ObjectRenderer( renderer ) { };
	ImageRenderer( const ImageRenderer& that ) = delete;

	virtual ~ImageRenderer( void ) noexcept;

	ImageRenderer& operator=( const ImageRenderer& that ) = delete;

	virtual void renderEntitySubtype( const EntitySubtype* target, const SDL_Rect& targetPosition ) override;
	virtual void renderTileSubtype( const TileSubtype* target, const SDL_Rect& targetPosition ) override;
private:
	std::map< const std::string, Image* > images;
};

#endif
