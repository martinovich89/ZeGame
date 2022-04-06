#include "Player.hpp"

size_t userId = 1;

Player::Player() : _id(userId), _name("unnamed"), _resources(), _lastCheck(get_time()), _extractors()
{
	(void)_resources;
	_extractors[1] = 1;
	_extractors[3] = 3;
	userId++;
}

Player::~Player()
{

}

Player::Player(const Player &other)
{
	*this = other;
}

Player	&Player::operator=(const Player &other)
{
	(void)other;
	return *this;
}

id	Player::getId() const
{
	return _id;
}

std::string Player::getName() const
{
	return _name;
}

double	Player::getResource(unsigned index) const
{
	return _resources[index];
}

void	Player::colonize(Planet &planet)
{
	if (!planet.getOwnerId())
	{
		planet.setOwnerID(_id);
		_ownedPlanets.push_back(planet.getId());
	}
	else
		std::cout << "error : can't colonize, planet already owned by " << planet.getOwnerId() << std::endl;
}

void	Player::updateResources()
{
	time_t timeLapse = get_time() - _lastCheck;
	_lastCheck = get_time();
	for (unsigned i = 0; i < 6; i++)
	{
		_resources[i] += timeLapse / 1000000.0 * _extractors[i];
	}
}
