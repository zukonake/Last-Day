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

void Camera::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	for( Point::coordinate iteratorY = position.y - viewRange.height, renderY = 0;
		iteratorY < position.y + viewRange.height;
		iteratorY++, renderY += zoom )
	{
		for( Point::coordinate iteratorX = position.x - viewRange.width, renderX = 0;
			iteratorX < position.x + viewRange.width;
			iteratorX++, renderX += zoom )
		{
			if( (iteratorX % ( 32 / zoom )*( 32 / zoom )) == 0 and (iteratorY % ( 32 / zoom )*( 32 / zoom )) == 0)
			{
				sf::Transform renderPosition;
				renderPosition.translate( renderX, renderY );
				target.draw( world.getTile( Point( iteratorX, iteratorY ) ), renderPosition );
				//renderHeightEffects( Point( iteratorX, iteratorY ), window , Point( renderX, renderY ), renderPosition );
			}
		}
	}
	return;
}

void Camera::renderHeightEffects( const Point& targetTilePosition, sf::RenderWindow& window, const Point& targetRenderPosition ) const noexcept
{//TODO is a mess
	uint8_t maximumAlpha = 150;
	double heightAlphaMultiplier = maximumAlpha / ( ( world.getGenerator().getMaximumTileHeight() * 2 ));
	const Tile& targetTile = world.getTile( targetTilePosition );
	int8_t alpha = ( targetTile.getHeight() + world.getGenerator().getMaximumTileHeight() );
	double alphaModifier = heightAlphaMultiplier * alpha;
	if( alphaModifier > maximumAlpha )
	{
		alphaModifier = maximumAlpha;
	}
	sf::RectangleShape rectangle( sf::Vector2f( 32, 32 ) );
	rectangle.setPosition( targetRenderPosition );
	rectangle.setFillColor( sf::Color( 0, 0, 0, maximumAlpha - alphaModifier ) );
	window.draw( rectangle );
	if( world.getTile( Point( targetTilePosition.x - 1, targetTilePosition.y ) ).getHeight() != targetTile.getHeight() )
	{
		sf::RectangleShape horizontalLine( sf::Vector2f( 1.0f, 32 ) );
		horizontalLine.setPosition( targetRenderPosition );
		horizontalLine.setFillColor( sf::Color( 0, 0, 0, 70 ) );
		window.draw( horizontalLine );
	}
	if( world.getTile( Point( targetTilePosition.x, targetTilePosition.y - 1) ).getHeight() != targetTile.getHeight() )
	{
		sf::RectangleShape verticalLine( sf::Vector2f( 32, 1.0f ) );
		verticalLine.setPosition( targetRenderPosition );
		verticalLine.setFillColor( sf::Color( 0, 0, 0, 70 ) );
		window.draw( verticalLine );
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
	if( value >= 1 and value <= 32 )
	{
		zoom = value;
		updateViewRange();
	}
	return;
}

void Camera::updateViewRange( void ) noexcept
{
	viewRange = (screenSize / zoom) / 2;
	return;
}
