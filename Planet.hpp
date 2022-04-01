#pragma once

#include <iostream>
#include "Utils.hpp"

class Planet
{
	private :
		double			_distFromStar;
		double			_size;
		bool			_resources[6];
		bool			_hasOceans;
		bool			_hasAtmosphere;
		id				_id;
		id				_ownerId;
//		std::vector<id>	_ownedPlanets;

	public :
		Planet();
		~Planet();
		Planet(const Planet &other);
		Planet &operator=(const Planet &other);

	void		roll(unsigned index, double starSize, unsigned planetAmount);

	double		getDist() const;
	double		getSize() const;
	bool		getResource(unsigned index) const;
	bool		getHasOceans() const;
	bool		getHasAtmosphere() const;
	id			getOwnerId() const;
	id			getId() const;

	void		setId(id id);
	void		setOwnerID(const size_t &id);
	void		setDist(const double dist);
};

std::ostream	&operator<<(std::ostream &out, Planet &toPrint);