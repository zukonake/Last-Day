#include "renderableObject.hpp"

RenderableObject::RenderableObject( std::istream& in ) noexcept
{
	in.ignore( 255, ' ' );
	in >> texturePath;
	loadTexture();
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

void RenderableObject::loadTexture( void )
{
	if( !texture.loadFromFile( texturePath ) )
	{
		throw std::runtime_error( "RenderableObject::loadTexture, couldn't load texture from file: " + texturePath + "." );
		return;
	}
	return;
}
