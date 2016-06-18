#ifndef SPRITE_HPP
#define SPRITE_HPP

class Sprite
{
	Image* sourceImage;
	SDL_Rect positionOnImage;
public:
	Sprite( Image* sourceImage, SDL_Rect positionOnImage );
	void render( Interface* targetInterface, SDL_Rect* targetPosition );
};

#endif
