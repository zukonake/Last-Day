#include "image.hpp"

std::istream& operator >> ( std::istream& in, Image& obj )
{
	const unsigned int maximumVariableLength = 256;
	std::string imagePath;
	in >> imagePath;
	//TODO load image
	return in;
}

std::ostream& operator << ( std::ostream& out, const Image& obj )
{
	return out;
}

Image::Image() : value( NULL )
{

}
