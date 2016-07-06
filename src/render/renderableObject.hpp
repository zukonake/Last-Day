#ifndef RENDERABLEOBJECT_HPP
#define RENDERABLEOBJECT_HPP

#include <cstdint>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
//
#include <geometry/point.hpp>

class RenderableObject
{
public:
	RenderableObject( std::istream& in ) noexcept;
	RenderableObject( void ) noexcept { }

	virtual void render( sf::RenderWindow& window, const Point& targetPosition ) const noexcept;
private:
	void loadTexture( void );

	sf::Texture texture;
	std::string texturePath;
};

#endif
