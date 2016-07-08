#include "camera.hpp"
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <world/tile/tile.hpp>
#include <world/world.hpp>
#include <world/worldGenerator.hpp>

Camera::Camera( const Point& position, World& world, const Rectangle& screenSize ) noexcept :
	Entity( position, nullptr, world ),
	mScreenSize( screenSize )
{
	updateViewRange();
}

void Camera::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	for( Point::coordinate iteratorY = mPosition.y - mViewRange.height, renderY = 0;
		iteratorY < mPosition.y + mViewRange.height;
		iteratorY++, renderY += mZoom )
	{
		for( Point::coordinate iteratorX = mPosition.x - mViewRange.width, renderX = 0;
			iteratorX < mPosition.x + mViewRange.width;
			iteratorX++, renderX += mZoom )
		{
			if( (iteratorX % ( 32 / mZoom )*( 32 / mZoom )) == 0 and (iteratorY % ( 32 / mZoom )*( 32 / mZoom )) == 0)
			{
				sf::Transform renderPosition;
				sf::RenderStates renderStates = states;
				renderStates.transform.translate( renderX, renderY );
				target.draw( mWorld.getTile( Point( iteratorX, iteratorY ) ), renderStates );
				std::shared_ptr< Entity > entity = mWorld.getEntity( Point( iteratorX, iteratorY ) );
				if( entity != nullptr )
				{
					target.draw( *entity, renderStates );
				}
				renderHeightEffects( Point( iteratorX, iteratorY ), target, renderStates );
			}
		}
	}
	return;
}

void Camera::renderHeightEffects( const Point& targetTilePosition, sf::RenderTarget& target, sf::RenderStates states ) const noexcept
{//TODO is a mess, TODO transfer rect rendering to tile class TODO
	uint8_t maximumAlpha = 150;
	double heightAlphaMultiplier = maximumAlpha / ( ( WorldGenerator::getMaximumTileHeight() * 2 ));
	const Tile& targetTile = mWorld.getTile( targetTilePosition );
	int8_t alpha = ( targetTile.getHeight() + WorldGenerator::getMaximumTileHeight() );
	double alphaModifier = heightAlphaMultiplier * alpha;
	if( alphaModifier > maximumAlpha )
	{
		alphaModifier = maximumAlpha;
	}
	sf::RectangleShape rectangle( sf::Vector2f( 32, 32 ) );
	rectangle.setFillColor( sf::Color( 0, 0, 0, maximumAlpha - alphaModifier ) );
	target.draw( rectangle, states );
	if( mWorld.getTile( Point( targetTilePosition.x - 1, targetTilePosition.y ) ).getHeight() != targetTile.getHeight() )
	{
		sf::RectangleShape verticalLine( sf::Vector2f( 1.0f, 32 ) );
		verticalLine.setFillColor( sf::Color( 0, 0, 0, 70 ) );
		target.draw( verticalLine, states );
	}
	if( mWorld.getTile( Point( targetTilePosition.x, targetTilePosition.y - 1) ).getHeight() != targetTile.getHeight() )
	{
		sf::RectangleShape horizontalLine( sf::Vector2f( 32, 1.0f ) );
		horizontalLine.setFillColor( sf::Color( 0, 0, 0, 70 ) );
		target.draw( horizontalLine, states );
	}
	return;
}

void Camera::move( const Direction& targetDirection )
{
	mPosition = mPosition.move( targetDirection );
}

void Camera::resizeZoom( const bool& direction ) noexcept
{
	if( direction and mZoom <= 16 )
	{
		mZoom *= 2;
		updateViewRange();
	}
	if( !direction and mZoom >= 2 )
	{
		mZoom /= 2;
		updateViewRange();
	}
	return;
}

void Camera::updateViewRange( void ) noexcept
{
	mViewRange = ( mScreenSize / mZoom ) / 2;
	return;
}
