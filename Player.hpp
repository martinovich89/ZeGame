#pragma once

#include "Galaxy.hpp"

class Player
{
	private :
		size_t				_id;
		std::string			_name;
		double				_resources[6];
		std::vector<id>		_ownedPlanets;
		time_t				_lastCheck;
		size_t				_extractors[6];

	public :
		Player();
		~Player();
		Player(const Player &other);
		Player &operator=(const Player &other);

		id	getId() const;
		std::string getName() const;
		double	getResource(unsigned index) const;

		void	updateResources();
		void	colonize(Planet &planet);
};
