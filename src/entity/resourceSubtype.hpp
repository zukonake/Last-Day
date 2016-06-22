#ifndef RESOURCESUBTYPE_HPP
#define RESOURCESUBTYPE_HPP

#include <string>
#include <iostream>

class ResourceSubtype
{
public:
	std::string name;

	ResourceSubtype();
	~ResourceSubtype();

	friend std::istream& operator >> ( std::istream& in, ResourceSubtype& obj );
	friend std::ostream& operator << ( std::ostream& out, const ResourceSubtype& obj );
};

#endif
