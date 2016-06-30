 #include "entitySubtype.hpp"

void EntitySubtype::render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const
{
	if( renderer == nullptr )
	{
		throw std::invalid_argument( "ERROR: EntitySubtype::render, null pointer given in argument 1." );
		return;
	}
	renderer->renderEntitySubtype( this, targetPosition );
	return;
}

EntitySubtype::EntitySubtype( std::istream& in ) noexcept :
	RenderableObject( in )
{
	in.ignore( 255, ' ' );
	in >> name;
}
