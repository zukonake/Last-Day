#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <iostream>
#include <SDL/SDL.h>
//
#include <render/image.hpp>
#include <render/interface.hpp>

class Sprite : protected Image
{
protected:
	SDL_Rect positionOnImage;
public:
	virtual void render( Interface* targetInterface, SDL_Rect* targetPosition );
protected:
	Sprite();
	virtual ~Sprite();

	friend std::istream& operator >> ( std::istream& in, Sprite& obj );
	friend std::ostream& operator << ( std::ostream& out, const Sprite& obj );
};

#endif
