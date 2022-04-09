#pragma once

#include <iostream>

class Menu
{
	private :
		int			_player_offset;
		int			_display_offset;
		int			_arrow_x;
		int			_arrow_y;

	public :
		Menu();
		~Menu();
		Menu(const Menu &other);
		Menu &operator=(const Menu &other);

		Menu(int display_offset);

		int	getPlayerOffset();
		int	getDisplayOffset();
		int	getArrowY();
		int	getArrowX();

		void	setArrowX(int x);
		void	setArrowY(int y);
};