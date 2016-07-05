#include "camera.hpp"
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <geometry/SDL_RectWrapper.hpp>
#include <render/objectRenderer/objectRenderer.hpp>
#include <world/tile/tile.hpp>
#include <world/world.hpp>

Camera::Camera( const Point& position, World& world, const Rectangle& screenSize ) noexcept :
	Entity( world, position, nullptr ),
	screenSize( screenSize )
{
	updateViewRange();
}

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
			world.getTile( Point( iteratorX, iteratorY ) ).render( objectRenderer, renderPosition );
			world.renderHeightEffects( Point( iteratorX, iteratorY ), objectRenderer, renderPosition );
		}
	}
	return;
}

void Camera::move( const Direction& targetDirection )
{
	position = position.move( targetDirection );
}

const uint8_t& Camera::getZoom( void ) const noexcept
{
	return zoom;
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

void Camera::updateViewRange( void ) noexcept
{
	viewRange = (screenSize / zoom) / 2;
	return;
}
