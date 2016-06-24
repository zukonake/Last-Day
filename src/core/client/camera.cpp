#include "camera.hpp"
#include <geometry/SDL_RectWrapper.hpp>

void Camera::render( SDL_Renderer* targetRenderer )
{
	for( Point::coordinate iteratorY = position.y - viewRange.height, renderY = 0;
		iteratorY < position.y + viewRange.height;
		iteratorY++, renderY += Tile::spriteSize )
	{
		for( Point::coordinate iteratorX = position.x - viewRange.width, renderX = 0;
			iteratorX < position.x + viewRange.width;
			iteratorX++, renderX += Tile::spriteSize )
		{
			SDL_RectWrapper renderPosition( renderX, renderY, Tile::spriteSize, Tile::spriteSize );
			world( Point( iteratorX, iteratorY ) )->render( targetRenderer, renderPosition );
		}
	}
}

void Camera::move( const Direction& direction )
{
	position.move( direction );
}

Camera::Camera( const Point& position, World& world ) :
	Entity< void >( position, world, NULL )
{

}

Camera::~Camera()
{

}
