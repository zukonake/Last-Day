#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include <cstdint>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
//
#include <geometry/point.hpp>

class Renderable : public sf::Drawable
{
public:
	Renderable( std::istream& in ) noexcept;
	Renderable( void ) noexcept { }
private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
	void loadTexture( void );

	sf::Texture mTexture;
	sf::Sprite mSprite;
	std::string mTexturePath;
};

#endif
