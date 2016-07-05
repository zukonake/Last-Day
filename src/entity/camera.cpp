#include "camera.hpp"
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <world/tile/tile.hpp>
#include <world/world.hpp>

Camera::Camera( const Point& position, World& world, const Rectangle& screenSize ) noexcept :
	Entity( world, position, nullptr ),
	screenSize( screenSize )
{
	updateViewRange();
}

void Camera::render( sf::RenderWindow& window ) const noexcept
{
	for( Point::coordinate iteratorY = position.y - viewRange.height, renderY = 0;
		iteratorY < position.y + viewRange.height;
		iteratorY++, renderY += zoom )
	{
		for( Point::coordinate iteratorX = position.x - viewRange.width, renderX = 0;
			iteratorX < position.x + viewRange.width;
			iteratorX++, renderX += zoom )
		{
			world.getTile( Point( iteratorX, iteratorY ) ).render( window, Point( renderX, renderY ) );
			world.renderHeightEffects( Point( iteratorX, iteratorY ), window , Point( renderX, renderY ) );
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
