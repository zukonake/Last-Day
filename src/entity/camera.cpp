#include "camera.hpp"

void Camera::render( ObjectRenderer* objectRenderer ) const
{
	if( objectRenderer == nullptr )
	{
		throw std::invalid_argument( "Camera::render, null pointer given in argument 1." );
		return;
	}
	for( Point::coordinate iteratorY = position.y - viewRange.height, renderY = 0;
		iteratorY < position.y + viewRange.height;
		iteratorY++, renderY += zoom )
	{
		for( Point::coordinate iteratorX = position.x - viewRange.width, renderX = 0;
			iteratorX < position.x + viewRange.width;
			iteratorX++, renderX += zoom )
		{
			SDL_RectWrapper renderPosition( renderX, renderY, zoom, zoom );
			world.renderTile( Point( iteratorX, iteratorY ), objectRenderer, renderPosition );
		}
	}
	return;
}

void Camera::setZoom( const uint8_t& value ) noexcept
{
	if( value <= 0 )
	{
		zoom = 1;
	}
	else
	{
		zoom = value;
	}
	updateViewRange();
	return;
}

Camera::Camera( const Point& position, World& world, const Rectangle& screenSize ) noexcept :
	Entity( nullptr, position ),
	world( world ),
	screenSize( screenSize )
{
	updateViewRange();
}
