#include "Menu.hpp"

Menu::Menu() : _player_offset(3), _display_offset(0), _arrow_x(0), _arrow_y(_player_offset + _display_offset)
{

}

Menu::~Menu()
{

}

Menu::Menu(const Menu &other)
{
	*this = other;
}

Menu	&Menu::operator=(const Menu &other)
{
	_player_offset = other._player_offset;
	_display_offset = other._display_offset;
	_arrow_x = other._arrow_x;
	_arrow_y = other._arrow_y;
	return (*this);
}

Menu::Menu(int display_offset) : _player_offset(3), _display_offset(display_offset), _arrow_x(0), _arrow_y(_player_offset + _display_offset)
{

}

int Menu::getPlayerOffset()
{
	return _player_offset;
}

int	Menu::getDisplayOffset()
{
	return _display_offset;
}

int Menu::getArrowX()
{
	return _arrow_x;
}

int Menu::getArrowY()
{
	return _arrow_y;
}

void	Menu::setArrowX(int x)
{
	_arrow_x = x;
}

void	Menu::setArrowY(int y)
{
	_arrow_y = y;
}
