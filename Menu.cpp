#include "Menu.hpp"
#include "Realm.hpp"

Menu::Menu() : _arrow_x(0), _arrow_y(0), _selectables(), _displayables(), _selected()
{

}

Menu::~Menu()
{

}
/*
Menu::Menu(const Menu &other)
{
	*this = other;
}

Menu	&Menu::operator=(const Menu &other)
{
	_arrow_x = other._arrow_x;
	_arrow_y = other._arrow_y;
	return (*this);
}

Menu::Menu(std::vector<std::string> &selectables, std::vector<std::string> *displayables)
{
	_selectables = selectables;
	_displayables = displayables;
	_selected = 0;
}*/

void	Menu::display(WINDOW *win)
{
	int x = 2;
	int y = 0;
	int i = 0;

	for(const auto& value: _selectables)
	{
    	if (i == _selected)
		{
			wattron(win, A_STANDOUT);
			mvwprintw(win, y, x, value.c_str());
			wattroff(win, A_STANDOUT);
		}
		else
		{
			mvwprintw(win, y, x, value.c_str());
		}
		x += value.length() + 1;
		i++;
	}
	i = 0;
	x = 6;
	y = 3;
	for (const auto &value: _displayables[_selected])
	{
		mvwprintw(win, y, x, value.c_str());
		y += 2;
	}
}

std::vector<std::string> &Menu::pick_selectable(Galaxy &galaxy, const std::vector<Menu> &menus)
{
//	std::vector<std::string> ret;
	Planet &planet = galaxy.getSys(menus[0]._selected).getPlanet(menus[1]._selected);

	switch (menus.size())
	{
		case 1:
			return (galaxy.getSys(menus[0]._selected).getSelectables());
			break;
		case 2:
			return (planet.getSelectables());
			break;
		case 3:
			switch (menus.back()._selected)
			{
				case 0:
					return (planet.getSlots()[_selected].getSelectables());
					break;
				case 1:
					break;
				case 2:
					break;
			}
			break;
	}
	return (galaxy.getSelectables());
//	return (ret);
}

std::vector<std::string> *Menu::pick_displayable(Galaxy &galaxy, const std::vector<Menu> &menus)
{
//	std::vector<std::string> ret;
	Planet &planet = galaxy.getSys(menus[0]._selected).getPlanet(menus[1]._selected);

	switch (menus.size())
	{
		case 1:
			return (galaxy.getSys(menus[0]._selected).getDisplayables());
			break;
		case 2:
			return (planet.getDisplayables());
			break;
		case 3:
			break;
	}
	return (galaxy.getSys(menus[0]._selected).getDisplayables());
//	return (ret);
}

Menu	&Menu::operator++()
{
	_selected++;
	if (_selected > static_cast<int>(_selectables.size() - 1))
		_selected = static_cast<int>(_selectables.size() - 1);
	return (*this);
}

Menu	Menu::operator++(int)
{
	Menu tmp = *this;
	++*this;
	return tmp;
}

Menu	&Menu::operator--()
{
	_selected--;
	if (_selected < 0)
		_selected = 0;
	return (*this);
}

Menu	Menu::operator--(int)
{
	Menu tmp = *this;
	--*this;
	return tmp;
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
