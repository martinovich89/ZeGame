#include "Slot.hpp"

std::string buildings[8] = {"empty", "Ore Extractor", "Gaz Extractor", "Worker Camp", "Spaceport", "Research Lab", "Factory", "Solar Plant"};

Slot::Slot() : _name("empty"), _type(0), _level(0)
{

}

Slot::~Slot()
{

}

void	Slot::build(int n)
{
	_name = buildings[n];
}

std::string	Slot::getName() const
{
	return (_name);
}

int	Slot::getType() const
{
	return (_type);
}

int Slot::getLevel() const
{
	return (_level);
}

std::vector<std::string> &Slot::getSelectables()
{
	return (_selectables);
}