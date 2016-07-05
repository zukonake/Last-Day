#include "entitySubtype.hpp"
#include <exception>
//
#include <render/objectRenderer/objectRenderer.hpp>

EntitySubtype::EntitySubtype( std::istream& in ) noexcept :
RenderableObject( in )
{
	in.ignore( 255, ' ' );
	in >> name;
}

void EntitySubtype::render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const
{
	if( renderer == nullptr )
	{
		throw std::invalid_argument( "EntitySubtype::render, null pointer given in argument 1." );
		return;
	}
	renderer->renderEntitySubtype( this, targetPosition );
	return;
}

const std::string& EntitySubtype::getName( void ) const noexcept
{
	return name;
}
