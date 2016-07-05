#include "world.hpp"
#include <SFML/Graphics.hpp>
//
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <data/dataset.hpp>
#include <world/worldGenerator.hpp>

World::World( Dataset& dataset ) noexcept :
	ChunkContainer( generator ),
	EntityContainer( dynamic_cast< ChunkContainer& >( *this )),
	dataset( dataset ),
	generator( *this )
{

}

void World::renderHeightEffects( const Point& targetTilePosition, sf::RenderWindow& window, const Point& targetRenderPosition ) noexcept
{
	uint8_t maximumAlpha = 150;
	double heightAlphaMultiplier = maximumAlpha / ( (WorldGenerator::getMaximumTileHeight() * 2 ));
	const Tile& targetTile = ChunkContainer::getTile( targetTilePosition );
	int8_t alpha = ( targetTile.getHeight() + WorldGenerator::getMaximumTileHeight() );
	double alphaModifier = heightAlphaMultiplier * alpha;
	if( alphaModifier > maximumAlpha )
	{
		alphaModifier = maximumAlpha;
	}
	sf::RectangleShape rectangle( sf::Vector2f( 32, 32 ) );
	rectangle.setPosition( targetRenderPosition );
	rectangle.setFillColor( sf::Color( 0, 0, 0, maximumAlpha - alphaModifier ) );
	window.draw( rectangle );
	if( ChunkContainer::getTile( Point( targetTilePosition.x - 1, targetTilePosition.y ) ).getHeight() != targetTile.getHeight() )
	{
		sf::RectangleShape horizontalLine( sf::Vector2f( 1.0f, 32 ) );
		horizontalLine.setPosition( targetRenderPosition );
		horizontalLine.setFillColor( sf::Color( 0, 0, 0, 70 ) );
		window.draw( horizontalLine );
	}
	if( ChunkContainer::getTile( Point( targetTilePosition.x, targetTilePosition.y - 1) ).getHeight() != targetTile.getHeight() )
	{
		sf::RectangleShape verticalLine( sf::Vector2f( 32, 1.0f ) );
		verticalLine.setPosition( targetRenderPosition );
		verticalLine.setFillColor( sf::Color( 0, 0, 0, 70 ) );
		window.draw( verticalLine );
	}
	return;
}

void World::simulate( void ) noexcept
{
	EntityContainer::simulate();
	return;
}

Dataset& World::getDataset( void ) const noexcept
{
	return dataset;
}
