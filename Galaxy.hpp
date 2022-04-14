#pragma once

#include "System.hpp"
#include <iostream>
#include <string>
#include <sstream>
//#include <vector>

class Galaxy
{
	private :
		System						*_sysTab;
		unsigned					_sysAmount;
		std::vector<std::string>	_selectables;
		std::vector<std::string>	*_displayables;

	public :
		Galaxy();
		~Galaxy();
		Galaxy(const Galaxy &other);
		Galaxy &operator=(const Galaxy &other);

		Galaxy(const unsigned sysAmount);
		
		System	&getSys(unsigned index) const;
		unsigned getSysAmount() const;
		std::vector<std::string> &getSelectables();
		std::vector<std::string> *getDisplayables();
};

std::ostream	&operator<<(std::ostream &out, Galaxy &toPrint);