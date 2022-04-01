#include "Comet.hpp"

Comet::Comet()
:	_size(my_random(0.000001, 0.00003)),
	_resourceType(my_random(2, 6))
{
	_destination = my_random(0, 20);
}

Comet::~Comet()
{

}

Comet::Comet(const Comet &other) : _size(0), _resourceType(0), _destination(0)
{
	*this = other;
}

Comet	&Comet::operator=(const Comet &other)
{
	_size = other._size;
	_resourceType = other._resourceType;
	_destination = other._destination;
	return (*this);
}