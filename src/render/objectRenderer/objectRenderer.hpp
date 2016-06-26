#ifndef OBJECTRENDERER_HPP
#define OBJECTRENDERER_HPP

#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>

class EntitySubtype;
class TileSubtype;

class ObjectRenderer
{
	SDL_Renderer* renderer;
public:
	virtual void renderEntitySubtype( const EntitySubtype* target, const SDL_Rect& targetPosition  ) = 0;
	virtual void renderTileSubtype( const TileSubtype* target, const SDL_Rect& targetPosition  ) = 0;

	SDL_Renderer* getRenderer( void ) const noexcept { return renderer; }

	ObjectRenderer( SDL_Renderer* renderer ) noexcept : renderer( renderer ) { }
};

#endif
