#include "camera.hpp"
#include <geometry/SDL_RectWrapper.hpp>
#include <world/tile.hpp>

void Camera::render( SDL_Surface& targetSurface )
{
	for( Point::coordinate iteratorY = position.y - viewRange, renderY = 0;
		iteratorY < position.y + viewRange;
		iteratorY++, renderY += Tile::spriteSize )
	{
		for( Point::coordinate iteratorX = position.x - viewRange, renderX = 0;
			iteratorX < position.x + viewRange;
			iteratorX++, renderX += Tile::spriteSize )
		{
			SDL_RectWrapper renderPosition( renderX, renderY, Tile::spriteSize, Tile::spriteSize );
			world( Point( iteratorX, iteratorY ) )->render( targetSurface, renderPosition );
		}
	}
}

void Camera::move( const Direction& direction )
{
	position.move( direction );
}

Camera::Camera( const Point& position, World& world, const uint8_t viewRange ) :
	position( position ),
	world( world ),
	viewRange( viewRange )
{

}

Camera::~Camera()
{

}
