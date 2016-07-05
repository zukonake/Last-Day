#include "SFMLAdapter.hpp"
#include <geometry/rectangle.hpp>

SFMLAdapter::SFMLAdapter( const Rectangle& windowSize, const std::string windowTitle ) noexcept :
	windowSize( windowSize ),
	windowTitle( windowTitle )
{

}

SFMLAdapter::~SFMLAdapter( void ) noexcept
{
	window.close();
}

void SFMLAdapter::initialize( void )
{
	window.create( sf::VideoMode( windowSize.width, windowSize.height, 32 ), windowTitle );
	window.clear( sf::Color( 0, 0, 0 ) );
}

void SFMLAdapter::deinitialize( void )
{
	window.close();
}

void SFMLAdapter::update( void ) noexcept
{
	window.display();
	window.clear( sf::Color( 0, 0, 0 ) );
}

bool SFMLAdapter::isRunning( void ) const noexcept
{
	return window.isOpen();
}

bool SFMLAdapter::isKeyPressed( sf::Keyboard::Key key ) const noexcept
{
	return keyboard.isKeyPressed( key );
}

std::vector< sf::Event > SFMLAdapter::getEvents( void ) noexcept
{
	std::vector< sf::Event > output;
	while( window.pollEvent( event ) )
	{
		output.push_back( event );
	}
	return output;
}

sf::RenderWindow& SFMLAdapter::getWindow( void ) noexcept
{
	return window;
}

const Rectangle& SFMLAdapter::getWindowSize( void ) const noexcept
{
	return windowSize;
}

const std::string& SFMLAdapter::getWindowTitle( void ) const noexcept
{
	return windowTitle;
}

sf::Time SFMLAdapter::getElapsedTime( void ) noexcept
{
	sf::Time output = clock.getElapsedTime();
	clock.restart();
	return output;
}
