#include "rectangle.hpp"

Rectangle::Rectangle( std::istream& in ) noexcept
{
	in.ignore( 255, ' ' );
	in >> width;
	in >> height;
}

Rectangle::operator sf::Vector2< float >( void ) const noexcept
{
	sf::Vector2< float > output;
	output.x = width;
	output.y = height;
	return output;
}

Rectangle::operator sf::Vector2< int >( void ) const noexcept
{
	sf::Vector2< int > output;
	output.x = width;
	output.y = height;
	return output;
}

Rectangle::operator Point( void ) const noexcept
{
	Point output;
	output.x = width;
	output.y = height;
	return output;
}

Rectangle Rectangle::operator * ( const int& mul ) const noexcept
{
	return Rectangle( width * mul, height * mul );
}

Rectangle Rectangle::operator / ( const int& div ) const noexcept
{
	return Rectangle( width / div, height / div );
}

Rectangle Rectangle::operator % ( const int& mod ) const noexcept
{
	return Rectangle( width % mod, height % mod );
}

Rectangle Rectangle::operator + ( const int& add ) const noexcept
{
	return Rectangle( width + add, height + add );
}

Rectangle Rectangle::operator - ( const int& sub ) const noexcept
{
	return Rectangle( width - sub, height - sub );
}

bool Rectangle::operator == ( const Rectangle& target ) const noexcept
{
	return width == target.width and height == target.height;
}
