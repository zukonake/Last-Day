#include "camera.hpp"

void Camera::render( Interface* targetInterface, SDL_Rect* targetPosition )
{
	for( unsigned int iteratorY = position->y - viewRange;
		iteratorY < position->y + viewRange;
		iteratorY++ )
	{
		for( unsigned int iteratorX = position->x - viewRange;
			iteratorX < position->x + viewRange;
			iteratorX++ )
		{
			( *world )( Point2D( iteratorX, iteratorY ) )->render( targetInterface, targetPosition );
		}
	}
}

Camera::Camera()
{

}