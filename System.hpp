#pragma once

#include "Planet.hpp"
#include "Comet.hpp"
#include <iostream>

class System
{
	private :
		double		_starSize;
		unsigned	_planetAmount;
		Planet		*_planets;
//		std::vector<Planet>	_planets;
		time_t		_cometFrequency;
		Comet		_nextComet;
		id			_id;

	public :
		System();
		~System();
		System(const System &other);
		System &operator=(const System &other);

		void	generateComet(double size, int resourceType, int destination);

		double				getStarSize() const;
		unsigned			getPlanetAmount() const;
		Planet		&getPlanet(unsigned index);
		id			getId() const;

		void		setId(id id);
};

std::ostream	&operator<<(std::ostream &out, System &toPrint);