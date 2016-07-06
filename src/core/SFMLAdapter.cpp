#include "SFMLAdapter.hpp"
#include <geometry/rectangle.hpp>

SFMLAdapter::SFMLAdapter( const Rectangle& windowSize, const std::string windowTitle ) noexcept :
	windowSize( windowSize ),
	windowTitle( windowTitle )
{

}

SFMLAdapter::~SFMLAdapter( void ) noexcept
{
	deinitialize();
}

void SFMLAdapter::initialize( void )
{
	window.create( sf::VideoMode( windowSize.width, windowSize.height, 32 ), windowTitle );
	if( !window.isOpen() )
	{
		throw std::runtime_error( "SFMLAdapter::initialize, couldn't initialize window." );
		return;
	}
	window.clear( sf::Color( 0, 0, 0 ) );
	return;
}

void SFMLAdapter::deinitialize( void ) noexcept
{
	window.close();
	return;
}

void SFMLAdapter::update( void ) noexcept
{
	window.display();
	window.clear( sf::Color( 0, 0, 0 ) );
	return;
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
