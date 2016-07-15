#include "userInterface.hpp"

UserInterface::UserInterface( const Point& position, const std::string& texturePath ) noexcept :
	Renderable( texturePath ),
	mPosition( position )
{

}

void UserInterface::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	sf::RenderStates renderStates = states;
	renderStates.transform.translate( mPosition );
	Renderable::draw( target, renderStates );
	return;
}
