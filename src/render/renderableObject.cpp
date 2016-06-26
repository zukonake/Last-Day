#include "renderableObject.hpp"

RenderableObject::RenderableObject( std::istream& in ) noexcept
{
	in.ignore( 255, ' ' );
	in >> imagePath;
}
