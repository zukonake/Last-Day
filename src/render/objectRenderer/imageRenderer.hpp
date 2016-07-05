#ifndef IMAGERENDERER_HPP
#define IMAGERENDERER_HPP

#include <string>
#include <map>
#include <SDL2/SDL.h>
//
#include <render/objectRenderer/objectRenderer.hpp>

class Image;
class EntitySubtype;
class TileSubtype;

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
