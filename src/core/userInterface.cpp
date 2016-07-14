#include "userInterface.hpp"

UserInterface::UserInterface( const std::string& texturePath ) noexcept :
	Renderable( texturePath )
{

}

void UserInterface::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	sf::RenderStates renderStates = states;
	renderStates.transform.translate( position );
	Renderable::draw( target, renderStates );
}
