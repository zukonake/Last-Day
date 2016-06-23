#ifndef RESOURCESUBTYPE_HPP
#define RESOURCESUBTYPE_HPP

#include <string>
#include <iostream>

class ResourceSubtype
{
public:
	std::string name;

	ResourceSubtype( std::istream& in );
	ResourceSubtype() { }
	~ResourceSubtype();
};

#endif
