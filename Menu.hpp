#pragma once

#include "Galaxy.hpp"
#include <iostream>
#include <vector>
#include <ncurses.h>

class Menu
{
	private :
		int			_arrow_x;
		int			_arrow_y;

	public :
		std::vector<std::string>	_selectables;
		std::vector<std::string>	*_displayables;
		int			_selected;
		Menu();
		~Menu();

		Menu(std::vector<std::string> &selectables, std::vector<std::string> *displayables) : _arrow_x(0), _arrow_y(0), _selectables(selectables), _displayables(displayables), _selected(0)
        {
 		}

		Menu &operator++(void);
		Menu operator++(int);
		Menu &operator--(void);
		Menu operator--(int);

		void	display(WINDOW *win);		
		std::vector<std::string> &pick_selectable(Galaxy &galaxy, const std::vector<Menu *> &menus);
		std::vector<std::string> *pick_displayable(Galaxy &galaxy, const std::vector<Menu *> &menus);

		int	getArrowY();
		int	getArrowX();

		void	setArrowX(int x);
		void	setArrowY(int y);
};