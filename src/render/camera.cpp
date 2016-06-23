#include "camera.hpp"
#include <world/tile.hpp>

void Camera::render( SDL_Surface& targetSurface, SDL_Rect& targetPosition ) const
{
	for( int iteratorY = position.y - viewRange, renderY = targetPosition.y;
		iteratorY < position.y + viewRange;
		iteratorY++, renderY += Tile::spriteSize )
	{
		for( int iteratorX = position.x - viewRange, renderX = targetPosition.x;
			iteratorX < position.x + viewRange;
			iteratorX++, renderX += Tile::spriteSize )
		{
			SDL_RectWrapper renderPosition( renderX, renderY, Tile::spriteSize, Tile::spriteSize );
			world( Point2D( iteratorX, iteratorY ) )->render( targetSurface, renderPosition );
		}
	}
}

Camera::Camera( Point2D position, World& world, const unsigned int& viewRange ) :
	position( position ),
	world( world ),
	viewRange( viewRange )
{

}

Camera::~Camera()
{

}
