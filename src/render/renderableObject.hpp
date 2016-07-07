#ifndef RENDERABLEOBJECT_HPP
#define RENDERABLEOBJECT_HPP

#include <cstdint>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
//
#include <geometry/point.hpp>

class RenderableObject : public sf::Drawable
{
public:
	RenderableObject( std::istream& in ) noexcept;
	RenderableObject( void ) noexcept { }
private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
	void loadTexture( void );

	sf::Texture mTexture;
	sf::Sprite mSprite;
	std::string mTexturePath;
};

#endif
