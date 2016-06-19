#ifndef RESOURCESUBTYPE_HPP
#define RESOURCESUBTYPE_HPP

class ResourceSubtype
{
	friend std::istream& operator >> ( std::istream& in, ResourceSubtype& obj );
	friend std::ostream& operator << ( std::ostream& out, const ResourceSubtype& obj );
};

#endif
