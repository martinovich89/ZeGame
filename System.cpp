#include "System.hpp"
/*
System::System()
:	_starSize(my_random(STARSIZE_MIN, STARSIZE_MAX)),
	_planetAmount(my_random(PLANETAMOUNT_MIN, PLANETAMOUNT_MAX)),
	_planets(new Planet[_planetAmount]),
	_cometFrequency(my_random(COMETSPAN_MIN, COMETSPAN_MAX))
{
	for (unsigned i = 0; i < _planetAmount; i++)
	{
		_planets[i].setId(_id << 8 | i);
	}
}*/

System::System()
:	_starSize(my_random(STARSIZE_MIN, STARSIZE_MAX)),
	_planetAmount(my_random(PLANETAMOUNT_MIN, PLANETAMOUNT_MAX)),
	_planets(new Planet[_planetAmount]),
	_cometFrequency(my_random(COMETSPAN_MIN, COMETSPAN_MAX))
{
	for (size_t i = 0; i < _planetAmount; i++)
	{
		_planets[i].roll(i + 1, _starSize, _planetAmount);
//		_planets.push_back(sample);
		_planets[i].setId(_id << 8 | i);
	}
}

System::~System()
{
	delete [] _planets;
}

System::System(const System &other) : _starSize(0), _planetAmount(0), _planets(), _cometFrequency(0)
{
	*this = other;
}

System	&System::operator=(const System &other)
{

	if (this == &other)
		return (*this);
	_starSize = other._starSize;
	_planetAmount = other._planetAmount;
	delete [] _planets;
	_planets = new Planet[other._planetAmount];
	_cometFrequency = other._cometFrequency;

	(void)other;
	return (*this);
}

Planet	&System::getPlanet(unsigned index)
{
	return (_planets[index]);
}

unsigned	System::getPlanetAmount() const
{
	return (_planetAmount);
}

double	System::getStarSize() const
{
	return (_starSize);
}

id		System::getId() const
{
	return (_id);
}

std::ostream &operator<<(std::ostream &out, System &toPrint)
{
	out << "=====> System X <=====" << std::endl << std::endl;
	out << "Star size : " << toPrint.getStarSize() << std::endl;
	out << "There are " << toPrint.getPlanetAmount() << " planets in this system. Which are : " << std::endl;
	for (unsigned i = 0; i < toPrint.getPlanetAmount(); i++)
	{
		out << toPrint.getPlanet(i) << std::endl;
	}
	return (out);
}

void	System::setId(id id)
{
	_id = id;
}