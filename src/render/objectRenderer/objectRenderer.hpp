#ifndef OBJECTRENDERER_HPP
#define OBJECTRENDERER_HPP

#include <SDL2/SDL.h>

class EntitySubtype;
class TileSubtype;

class ObjectRenderer
{
public:
	ObjectRenderer( SDL_Renderer* renderer ) noexcept : renderer( renderer ) { }
	virtual ~ObjectRenderer( void ) noexcept { }

	virtual void renderEntitySubtype( const EntitySubtype* target, const SDL_Rect& targetPosition  ) = 0;
	virtual void renderTileSubtype( const TileSubtype* target, const SDL_Rect& targetPosition  ) = 0;

	SDL_Renderer* getRenderer( void ) const noexcept { return renderer; }
private:
	SDL_Renderer* renderer;
};

#endif
