#include "camera.hpp"

void Camera::render( UserInterface* targetUserInterface, SDL_Rect* targetPosition )
{
	for( unsigned int iteratorY = position.y - viewRange;
		iteratorY < position.y + viewRange;
		iteratorY++ )
	{
		for( unsigned int iteratorX = position.x - viewRange;
			iteratorX < position.x + viewRange;
			iteratorX++ )
		{
			world( Point2D( iteratorX, iteratorY ) ).render( targetUserInterface, targetPosition );
		}
	}
}

Camera::Camera( const Point2D& position, World& world ) : position( position ), world( world )
{

}

Camera::~Camera()
{

}
