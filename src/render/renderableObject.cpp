#include "renderableObject.hpp"

RenderableObject::RenderableObject( std::istream& in ) noexcept
{
	in.ignore( 255, ' ' );
	std::string texturePath;
	in >> texturePath;
	loadTexture( texturePath );
}

void RenderableObject::render( sf::RenderWindow& window, const Point& targetPosition ) const noexcept
{
	sf::Sprite sprite;
	sprite.setTexture( texture );
	sprite.setTextureRect( sf::IntRect( 0, 0, 32, 32 ) );
	sprite.setPosition( targetPosition );
	window.draw( sprite );
	return;
}

void RenderableObject::loadTexture( const std::string& texturePath )
{
	texture.loadFromFile( texturePath );
	return;
}
