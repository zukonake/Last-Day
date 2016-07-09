#ifndef SFMLADAPTER_HPP
#define SFMLADAPTER_HPP

#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//
#include <nonCopyable.hpp>
#include <geometry/rectangle.hpp>

class SFMLAdapter : sf::NonCopyable
{
public:
	SFMLAdapter( const Rectangle& windowSize, const std::string windowTitle ) noexcept;

	~SFMLAdapter( void ) noexcept;

	void initialize( void );
	void deinitialize( void ) noexcept;

	void update( void ) noexcept;

	bool isRunning( void ) const noexcept;
	bool isKeyPressed( sf::Keyboard::Key key ) const noexcept;

	std::vector< sf::Event > getEvents( void ) noexcept;
	sf::RenderWindow& getWindow( void ) noexcept;
	const Rectangle& getWindowSize( void ) const noexcept;
	const std::string& getWindowTitle( void ) const noexcept;
private:
	sf::RenderWindow mWindow;
	sf::Event mEvent;
	sf::Keyboard mKeyboard;

	Rectangle mWindowSize;
	std::string mWindowTitle;
};

#endif
