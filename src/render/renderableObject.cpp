#include "renderableObject.hpp"

RenderableObject::RenderableObject( std::istream& in ) noexcept
{
	in.ignore( 255, ' ' );
	in >> texturePath;
	loadTexture();
	sprite.setTexture( texture );
	sprite.setTextureRect( sf::IntRect( 0, 0, 32, 32 ) );
}

void RenderableObject::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw( sprite , states );
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
