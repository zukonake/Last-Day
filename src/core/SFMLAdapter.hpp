#ifndef SFMLADAPTER_HPP
#define SFMLADAPTER_HPP

#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//
#include <geometry/rectangle.hpp>

class SFMLAdapter
{
public:
	SFMLAdapter( const Rectangle& windowSize, const std::string windowTitle ) noexcept;
	SFMLAdapter( const SFMLAdapter& that ) = delete;

	~SFMLAdapter( void ) noexcept;

	SFMLAdapter& operator=( const SFMLAdapter& that ) = delete;

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
	sf::RenderWindow window;
	sf::Event event;
	sf::Keyboard keyboard;

	Rectangle windowSize;
	std::string windowTitle;
};

#endif
