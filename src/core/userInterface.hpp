#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <string>
#include <SFML/Graphics.hpp>
//
#include <nonCopyable.hpp>
#include <geometry/point.hpp>
#include <render/renderable.hpp>

class UserInterface : public Renderable, NonCopyable
{
public:
	UserInterface( const std::string& texturePath ) noexcept;

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
private:
	Point position;
};

#endif
