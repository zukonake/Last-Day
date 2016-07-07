#include "renderableObject.hpp"

RenderableObject::RenderableObject( std::istream& in ) noexcept
{
	in.ignore( 255, ' ' );
	in >> mTexturePath;
	loadTexture();
	mSprite.setTexture( mTexture );
	mSprite.setTextureRect( sf::IntRect( 0, 0, 32, 32 ) );
}

void RenderableObject::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw( mSprite , states );
	return;
}

void RenderableObject::loadTexture( void )
{
	if( !mTexture.loadFromFile( mTexturePath ) )
	{
		throw std::runtime_error( "RenderableObject::loadTexture, couldn't load texture from file: " + mTexturePath + "." );
		return;
	}
	return;
}
