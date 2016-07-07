#include "SFMLAdapter.hpp"
#include <geometry/rectangle.hpp>

SFMLAdapter::SFMLAdapter( const Rectangle& windowSize, const std::string windowTitle ) noexcept :
	mWindowSize( windowSize ),
	mWindowTitle( windowTitle )
{

}

SFMLAdapter::~SFMLAdapter( void ) noexcept
{
	deinitialize();
}

void SFMLAdapter::initialize( void )
{
	mWindow.create( sf::VideoMode( mWindowSize.width, mWindowSize.height, 32 ), mWindowTitle );
	if( !mWindow.isOpen() )
	{
		throw std::runtime_error( "SFMLAdapter::initialize, couldn't initialize window." );
		return;
	}
	mWindow.clear( sf::Color( 0, 0, 0 ) );
	return;
}

void SFMLAdapter::deinitialize( void ) noexcept
{
	mWindow.close();
	return;
}

void SFMLAdapter::update( void ) noexcept
{
	mWindow.display();
	mWindow.clear( sf::Color( 0, 0, 0 ) );
	return;
}

bool SFMLAdapter::isRunning( void ) const noexcept
{
	return mWindow.isOpen();
}

bool SFMLAdapter::isKeyPressed( sf::Keyboard::Key key ) const noexcept
{
	return mKeyboard.isKeyPressed( key );
}

std::vector< sf::Event > SFMLAdapter::getEvents( void ) noexcept
{
	std::vector< sf::Event > output;
	while( mWindow.pollEvent( mEvent ) )
	{
		output.push_back( mEvent );
	}
	return output;
}

sf::RenderWindow& SFMLAdapter::getWindow( void ) noexcept
{
	return mWindow;
}

const Rectangle& SFMLAdapter::getWindowSize( void ) const noexcept
{
	return mWindowSize;
}

const std::string& SFMLAdapter::getWindowTitle( void ) const noexcept
{
	return mWindowTitle;
}
