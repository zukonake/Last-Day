#ifndef SFMLADAPTER_HPP
#define SFMLADAPTER_HPP

#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//
#include <nonCopyable.hpp>
#include <geometry/point.hpp>

class SFMLAdapter : NonCopyable
{
public:
	SFMLAdapter( void ) = default;

	virtual ~SFMLAdapter( void ) noexcept;

	void initialize( const Point& windowSize, const std::string& windowTitle );
	void deinitialize( void ) noexcept;

	void update( void ) noexcept;

	bool isRunning( void ) const noexcept;
	bool isKeyPressed( sf::Keyboard::Key key ) const noexcept;

	std::vector< sf::Event > getEvents( void ) noexcept;
	sf::RenderWindow& getWindow( void ) noexcept;
	Point getWindowSize( void ) const noexcept;
private:
	sf::RenderWindow mWindow;
	sf::Event mEvent;
	sf::Keyboard mKeyboard;
};

#endif
