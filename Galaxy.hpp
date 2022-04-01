#pragma once

#include "System.hpp"
#include <iostream>

class Galaxy
{
	private :
		System		*_sysTab;
		unsigned	_sysAmount;

	public :
		Galaxy();
		~Galaxy();
		Galaxy(const Galaxy &other);
		Galaxy &operator=(const Galaxy &other);

		Galaxy(const unsigned sysAmount);
		
		System	&getSys(unsigned index) const;
		unsigned getSysAmount() const;
};

std::ostream	&operator<<(std::ostream &out, Galaxy &toPrint);