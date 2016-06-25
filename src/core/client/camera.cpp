#include "camera.hpp"

void Camera::render( SDL_Renderer* targetRenderer )
{
	for( Point::coordinate iteratorY = position.y - viewRange.height, renderY = 0;
		iteratorY < position.y + viewRange.height;
		iteratorY++, renderY += TileSubtype::spriteSize )
	{
		for( Point::coordinate iteratorX = position.x - viewRange.width, renderX = 0;
			iteratorX < position.x + viewRange.width;
			iteratorX++, renderX += TileSubtype::spriteSize )
		{
			SDL_RectWrapper renderPosition( renderX, renderY, TileSubtype::spriteSize, TileSubtype::spriteSize );
			world.renderTile( Point( iteratorX, iteratorY ), targetRenderer, renderPosition );
		}
	}
}

Camera::Camera( const Point& position, World& world ) :
	Entity< void >( position, world )
{

}

Camera::~Camera()
{

}
