#ifndef ENTITYSUBTYPE_HPP
#define ENTITYSUBTYPE_HPP

#include <string>
#include <iostream>
//
#include <render/renderable.hpp>

class EntitySubtype : public Renderable
{
public:
	explicit EntitySubtype( std::istream& in ) noexcept;
	EntitySubtype( void ) = default;
	
	virtual ~EntitySubtype( void ) = default;

	const std::string& getName( void ) const noexcept;
private:
	std::string mName;
};

#endif
