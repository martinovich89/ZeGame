#include "Galaxy.hpp"

Galaxy::Galaxy() : _sysTab(new System[SYSTEM_ACCOUNT]), _sysAmount(SYSTEM_ACCOUNT)
{
	for (unsigned i = 0; i < _sysAmount; i++)
	{
		_sysTab[i].setId(i);
	}
}

Galaxy::~Galaxy()
{
	delete [] _sysTab;
}

Galaxy::Galaxy(const Galaxy &other) : _sysTab(new System[0]), _sysAmount(0)
{
	*this = other;
}

Galaxy	&Galaxy::operator=(const Galaxy &other)
{
	if (this == &other)
		return (*this);
	delete [] (_sysTab);
	_sysTab = new System[other._sysAmount];
	_sysAmount = other._sysAmount;
	for (unsigned i = 0; i < other._sysAmount; i++)
	{
		_sysTab[i] = other._sysTab[i];
	}
	return (*this);
}

Galaxy::Galaxy(unsigned sysAmount) : _sysTab(new System[sysAmount]), _sysAmount(sysAmount)
{

}

System	&Galaxy::getSys(unsigned index) const
{
	return (_sysTab[index]);
}

unsigned	Galaxy::getSysAmount() const
{
	return (_sysAmount);
}

std::ostream	&operator<<(std::ostream &out, Galaxy &toPrint)
{
	out << "Amount of known systems : " << toPrint.getSysAmount() << std::endl;
	out << "List of known systems : " << std::endl;
	for (unsigned i = 0; i < toPrint.getSysAmount(); i++)
	{
		out << toPrint.getSys(i) << std::endl;
	}
	return (out);
}