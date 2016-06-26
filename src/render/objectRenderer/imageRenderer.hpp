#ifndef IMAGERENDERER_HPP
#define IMAGERENDERER_HPP

#include <exception>
#include <string>
#include <map>
#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>
#include <render/objectRenderer/objectRenderer.hpp>
#include <render/image/image.hpp>
#include <render/image/PNGImage.hpp>
#include <world/tileSubtype.hpp>
#include <entity/entitySubtype.hpp>

class ImageRenderer : public ObjectRenderer
{
	std::map< const std::string, Image* > images;
public:
	virtual void renderEntitySubtype( const EntitySubtype* target, const SDL_Rect& targetPosition ) override;
	virtual void renderTileSubtype( const TileSubtype* target, const SDL_Rect& targetPosition ) override;

	ImageRenderer( SDL_Renderer* renderer ) noexcept;

	virtual ~ImageRenderer( void ) noexcept;
};

#endif
