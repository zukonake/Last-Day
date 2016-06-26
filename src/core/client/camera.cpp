#include "camera.hpp"

void Camera::render( ObjectRenderer* objectRenderer )
{
	viewRange = Rectangle( 1280 / TileSubtype::getSpriteSize(), 768 / TileSubtype::getSpriteSize() );
	for( Point::coordinate iteratorY = position.y - viewRange.height, renderY = 0;
		iteratorY < position.y + viewRange.height;
		iteratorY++, renderY += TileSubtype::getSpriteSize() )
	{
		for( Point::coordinate iteratorX = position.x - viewRange.width, renderX = 0;
			iteratorX < position.x + viewRange.width;
			iteratorX++, renderX += TileSubtype::getSpriteSize() )
		{
			SDL_RectWrapper renderPosition( renderX, renderY, TileSubtype::getSpriteSize(), TileSubtype::getSpriteSize() );
			world.renderTile( Point( iteratorX, iteratorY ), objectRenderer, renderPosition );
		}
	}
}

Camera::Camera( const Point& position, World& world ) :
	Entity< void >( NULL, position, world )
{

}

Camera::~Camera()
{

}
