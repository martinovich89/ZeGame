#include "Planet.hpp"

Planet::Planet()
:	_distFromStar(my_random(50.0, 10000.0)),
	_size(my_random(STARSIZE_MIN / 200.0, STARSIZE_MIN / 20.0)),
	_resources(),
	_hasOceans(my_random(0, 1 + INCLUSIVE)),
	_hasAtmosphere(my_random(0, 1 + INCLUSIVE)),
	_ownerId(0),
	_selectable_actions(),
	_displayable_actions(new std::vector<std::string>[8]),
	_slots()
{
	unsigned randResource = my_random(2, 6);

	_resources[0] = 1;
	_resources[1] = 1;
	for (unsigned i = 2; i < 6; i++)
	{
		_resources[i] = (i == randResource);
	}
	_selectable_actions.push_back("BUILD");
	_selectable_actions.push_back("DESTROY");
	_selectable_actions.push_back("COLONIZE");
}

Planet::~Planet()
{
	delete [] _displayable_actions;
}

Planet::Planet(const Planet &other)
:	_distFromStar(),
	_size(),
	_resources(),
	_hasOceans(),
	_hasAtmosphere()
{
	*this = other;
}

Planet &Planet::operator=(const Planet &other)
{
	_distFromStar = other._distFromStar;
	_size = other._size;
	_hasOceans = other._hasOceans;
	_hasAtmosphere = other._hasAtmosphere;
	for (unsigned i = 0; i < 6; i++)
	{
		_resources[0] = other._resources[0];
	}
	return (*this);
}

void	Planet::roll(unsigned i, double starSize, unsigned planetAmount)
{
	double min = static_cast<double>(i) / static_cast<double>(planetAmount) - static_cast<double>(0.4) / static_cast<double>(planetAmount);
	double max = static_cast<double>(i) / static_cast<double>(planetAmount) + static_cast<double>(0.4) / static_cast<double>(planetAmount);
	unsigned randResource = my_random(2, 6);

	_resources[0] = 1;
	_resources[1] = 1;
	for (unsigned j = 2; j < 6; j++)
	{
		_resources[j] = (j == randResource);
	}

	setDist(my_random((starSize * (10000.0 - 50.0) * min), starSize * (10000.0 - 50.0) * max));

	if (static_cast<double>(i) / static_cast<double>(planetAmount) > 0.5)
		_size = my_random(starSize / 50.0, starSize / 20.0);
	else
		_size = my_random(starSize / 200, starSize / 80);

	_hasOceans = my_random(0, 1 + INCLUSIVE);
	_hasAtmosphere = my_random(0, 1 + INCLUSIVE);
}

double	Planet::getDist() const
{
	return _distFromStar;
}

double	Planet::getSize() const
{
	return _size;
}

bool	Planet::getResource(unsigned index) const
{
	return _resources[index];
}

bool	Planet::getHasOceans() const
{
	return _hasOceans;
}

bool	Planet::getHasAtmosphere() const
{
	return _hasAtmosphere;
}

id		Planet::getOwnerId() const
{
	return _ownerId;
}

id		Planet::getId() const
{
	return _id;
}

std::vector<std::string> &Planet::getSelectables()
{
	return _selectable_actions;
}

std::vector<std::string> *Planet::getDisplayables()
{
	return _displayable_actions;
}

Slot	*Planet::getSlots()
{
	return _slots;
}

std::ostream	&operator<<(std::ostream &out, Planet &toPrint)
{
	extern std::string resources[6];

	out << "Planet ID : " << toPrint.getId() << std::endl;
	if (toPrint.getOwnerId())
		out << "Owner ID : " << toPrint.getOwnerId() << std::endl;
	out << "Distance from star : " << toPrint.getDist() << std::endl;
	out << "Planet size : " << toPrint.getSize() << std::endl;
	out << "Resources : " << std::endl;
	for (unsigned i = 0; i < 6; i++)
	{
		if (toPrint.getResource(i))
			out << "- " << resources[i] << std::endl;
	}

	if (toPrint.getHasOceans())
		out << "Planet has oceans" << std::endl;
	
	if (toPrint.getHasAtmosphere())
		out << "Planet has Atmosphere" << std::endl;
	return (out);
}

void	Planet::setId(id id)
{
	_id = id;
}

void	Planet::setOwnerID(const size_t &id)
{
	_ownerId = id;
}

void	Planet::setDist(const double dist)
{
	_distFromStar = dist;
}