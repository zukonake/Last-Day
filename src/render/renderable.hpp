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
	explicit Renderable( std::istream& in ) noexcept;
	Renderable( const std::string& texturePath ) noexcept;
	Renderable( void ) = default;
protected:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
private:
	void loadTexture( void );
	void setupSprite( void ) noexcept;

	sf::Texture mTexture;
	sf::Sprite mSprite;
	std::string mTexturePath;
};

#endif
