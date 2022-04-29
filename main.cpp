#include "Realm.hpp"


// std::string	resources[6] = {"Ore", "Gaz", "Pearl", "Aether", "Uranium", "Adamantium"};
// std::string buildings[8] = {"empty", "Ore Extractor", "Gaz Extractor", "Worker Camp", "Spaceport", "Research Lab", "Factory", "Solar Plant"};
int menu_type = 1;
/*
void	display_player(Player &player)
{
	int x = 0;
	int y = 0;
	// player infos
	mvprintw(y,x,"Player %zu", player.getId());
	x += TERM_WIDTH / PLAYER_ATTRIBUTES;
	mvprintw(y,x,"Name : %s", (player.getName().c_str()));
	x += TERM_WIDTH / PLAYER_ATTRIBUTES;
	mvprintw(y,x,"[ %12i | %12i | %12i | %12i | %12i | %12i ]", static_cast<int>(player.getResource(0)), static_cast<int>(player.getResource(1)), static_cast<int>(player.getResource(2)), static_cast<int>(player.getResource(3)), static_cast<int>(player.getResource(4)), static_cast<int>(player.getResource(5)));
}

void	display_galaxy(Galaxy &galaxy)
{
	int offset = 3;
	int x = 1;
	int y = 0 + offset;
	// system members
	mvprintw(y,x,"Systems");
	x += TERM_WIDTH / SYSTEM_ATTRIBUTES;
	mvprintw(y,x,"Star size");
	x += TERM_WIDTH / SYSTEM_ATTRIBUTES;
	mvprintw(y,x,"Amount of planets");
	x += TERM_WIDTH / SYSTEM_ATTRIBUTES;
	mvprintw(y,x,"Next comet");
	// system list
	for (unsigned i = 0; i < SYSTEM_ACCOUNT; i++)
	{
		y += 2;
		x = 1;
		mvprintw(y,x,"%zu", galaxy.getSys(i).getId());
		x += TERM_WIDTH / SYSTEM_ATTRIBUTES;
		mvprintw(y,x,"%lf", galaxy.getSys(i).getStarSize());
		x += TERM_WIDTH / SYSTEM_ATTRIBUTES;	
		mvprintw(y,x,"%zu", galaxy.getSys(i).getPlanetAmount());
	}
}

void	display_system(System &system)
{
	int offset = 3;
	int x = 1;
	int y = 0 + offset;

	// planet attributes
	mvprintw(y,x,"Planets");
	x += TERM_WIDTH / PLANET_ATTRIBUTES;
	mvprintw(y,x,"Size");
	x += TERM_WIDTH / PLANET_ATTRIBUTES;
	mvprintw(y,x,"Distance from Star");
	x += TERM_WIDTH / PLANET_ATTRIBUTES;
	mvprintw(y,x,"Has oceans");
	x += TERM_WIDTH / PLANET_ATTRIBUTES;
	mvprintw(y,x,"Has atmosphere");
	x += TERM_WIDTH / PLANET_ATTRIBUTES;
	mvprintw(y,x,"Owned by");

	// planet stats
	for (unsigned i = 0; i < system.getPlanetAmount(); i++)
	{
		y += 2;
		x = 1;
		mvprintw(y,x,"%zu", system.getPlanet(i).getId());
		x += TERM_WIDTH / PLANET_ATTRIBUTES;
		mvprintw(y,x,"%lf", system.getPlanet(i).getSize());
		x += TERM_WIDTH / PLANET_ATTRIBUTES;	
		mvprintw(y,x,"%lf", system.getPlanet(i).getDist());
		x += TERM_WIDTH / PLANET_ATTRIBUTES;	
		mvprintw(y,x,"%zu", system.getPlanet(i).getHasOceans());
		x += TERM_WIDTH / PLANET_ATTRIBUTES;	
		mvprintw(y,x,"%zu", system.getPlanet(i).getHasAtmosphere());
		x += TERM_WIDTH / PLANET_ATTRIBUTES;	
		mvprintw(y,x,"%zu", system.getPlanet(i).getOwnerId());
	}

	y += 2;
	x = 1;
	mvprintw(y,x,"Back to previous menu");
}

int	display_arrow(int c, int attr, int count, int newline, Menu &menu)
{
	int offset = menu.getPlayerOffset() + menu.getDisplayOffset();
	int ret = 0;

	if (c == 119 && menu.getArrowY() > 0 + offset)
	{
		mvprintw(menu.getArrowY(),menu.getArrowX()," ");
		menu.setArrowY(menu.getArrowY() - newline);
	}
	else if (c == 97 && menu.getArrowX() > 0)
	{
		mvprintw(menu.getArrowY(),menu.getArrowX()," ");
		menu.setArrowX(menu.getArrowX() - TERM_WIDTH / attr);
	}
	else if (c == 115 && menu.getArrowY() < newline * (count - 1) + offset)
	{
		mvprintw(menu.getArrowY(),menu.getArrowX()," ");
		menu.setArrowY(menu.getArrowY() + newline);
	}
	else if (c == 115 && menu.getArrowY() < newline * (count) + offset && menu.getArrowX() == 0 && menu_type > 1)
	{
		mvprintw(menu.getArrowY(),menu.getArrowX()," ");
		menu.setArrowY(menu.getArrowY() + newline);
	} 
	else if (c == 100 && menu.getArrowY() < newline * (count) + offset && menu.getArrowX() < static_cast<int>(static_cast<double>(attr - 1) * static_cast<double>(TERM_WIDTH / attr)))
	{
		mvprintw(menu.getArrowY(),menu.getArrowX()," ");
		menu.setArrowX(menu.getArrowX() + TERM_WIDTH / attr);
	}
	else if (c == 101 && menu_type > 1 && menu.getArrowX() == 0 && menu.getArrowY() == newline * (count) + offset)
	{
		clear();
		menu_type--;
		menu.setArrowY(offset); menu.setArrowX(0);
		return (0);
	}
	else if (c == 101 && menu_type < 3 && menu.getArrowY() >= offset)
	{
		clear();
		menu_type++;
		ret = (menu.getArrowY() - offset + newline) / 2;
		menu.setArrowY(offset); menu.setArrowX(0);
		return (ret);
	}
	mvprintw(menu.getArrowY(),menu.getArrowX(),">");
	return (0);
}

void	display_planet(Planet &planet)
{
	(void)planet;
	int offset = 3;
	int x = 1;
	int y = 0 + offset;

	// planet attributes
	mvprintw(y,x,"BUILD");
	y += 2;
	mvprintw(y,x,"DESTROY");
	y += 2;
	mvprintw(y,x,"ANALYSIS");

	y += 2;
	x = 1;
	mvprintw(y,x,"Back to previous menu");
}


int main(void)
{
	Menu galaxy(1 * 2);
	Menu system(1 * 2);
	Menu planet(0);
	Player Martin;
	Galaxy bigMama;
	time_t chrono;
	std::string input;
	time_t start;
//	int	menu = 1;
//	(void)menu;

	System mySystem = bigMama.getSys(my_random(0, SYSTEM_ACCOUNT - 1));
	Martin.colonize(mySystem.getPlanet(my_random(0u, mySystem.getPlanetAmount() - 1)));

	start = get_time();
	chrono = (get_time() - start) / 1000;
	(void)chrono;

	initscr();

//	int offset = 3;
	int c = 0;
	int ret = 0;
	size_t	toDisplay = 0;
//	int arrow_y = 0 + offset;
//	int arrow_x = 0;

	noecho();
	cbreak();
	timeout(1);
	while ((c = getch()) != 27)
	{
		display_player(Martin);

		Martin.updateResources();

		switch (menu_type)
		{
			case 1:
				toDisplay = 0;
				display_galaxy(bigMama);
				ret = display_arrow(c, SYSTEM_ATTRIBUTES, SYSTEM_ACCOUNT, GALAXY_MENU_NEWLINE, galaxy);
				break;
			case 2:
				toDisplay = (ret != 0) ? ret : toDisplay;
				display_system(bigMama.getSys((toDisplay & 0xFF) - 1));
				ret = display_arrow(c, PLANET_ATTRIBUTES, bigMama.getSys((toDisplay & 0xFF) - 1).getPlanetAmount(), SYSTEM_MENU_NEWLINE, system);
				break;
			case 3:
				toDisplay |= (ret != 0) ? ret << 8 : toDisplay;
				display_planet(bigMama.getSys((toDisplay & 0xFF) - 1).getPlanet((toDisplay >> 8) - 1));
				ret = display_arrow(c, PLANET_MENU_COLUMNS, PLANET_MENU_OPTIONS, PLANET_MENU_NEWLINE, planet);
				break;
		}

		mvprintw(25,0,"");
		refresh();
	}

	endwin();
	return (0);
}*/

int main(void)
{
	int window = 0;
	Player Martin;
	Galaxy bigMama;
//	time_t chrono;
//	time_t start;
	Menu first(bigMama.getSelectables(), bigMama.getDisplayables());

	std::vector<Menu> menus;
	menus.push_back(first);

	System mySystem = bigMama.getSys(my_random(0, SYSTEM_ACCOUNT - 1));
	Martin.colonize(mySystem.getPlanet(my_random(0u, mySystem.getPlanetAmount() - 1)));

/*	menus.push_back(new Menu(menus.back()->pick_selectable(bigMama, menus), menus.back()->pick_displayable(bigMama, menus)));
	std::cout << menus.back()->_selectables.back() << std::endl;

	for (Menu *element : menus)
    	delete(element);

	return (0);
*/
	initscr();
	noecho();
	curs_set(0);
	cbreak();
	timeout(10);

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW *win[2] = {newwin(yMax - 5, xMax, 5, 0), newwin(yMax - 5, xMax, 5, 0)};
	WINDOW *win2 = newwin(4, xMax, 0, 0);
	box(win[0], 0, 0);
	box(win[1], 0, 0);
	box(win2, 0, 0);
/*
	mvwprintw(win, 0, 2, "File");
	mvwprintw(win, 0, 7, "Edit");
	mvwprintw(win, 0, 12, "Options");
*/
	keypad(win[0], 1);
	keypad(win[1], 1);

	set_escdelay(10);
//	wrefresh(win);

	int ch = -1;
	int ch_display = 0;
	while ((ch = getch()) != 27)
	{
		ch_display = (ch != -1) ? ch : ch_display;
		if (ch_display)
			mvwprintw(win[window], 20, 2, "%d\n", ch_display);
		switch(ch)
		{
			case 'a':
				(menus.back())--;
				break;
			case 'd':
				(menus.back())++;
				break;
			case 'e':
				if (menus.size() < 3 || (menus.size() == 3 && menus.back()._selected < 2))
					menus.push_back(Menu(menus.back().pick_selectable(bigMama, menus), menus.back().pick_displayable(bigMama, menus)));
				wclear(win[window]);
				break;
			case 'q':
				if (menus.size() > 1 && window == 0)
				{
					menus.pop_back();
					wclear(win[window]);
				}
				break;
		}

		box(win[window], 0, 0);
		Martin.updateResources();
		menus.back().display(win[window]);
		mvwprintw(win2, 1, 1, Martin.getName().c_str());
		mvwprintw(win2, 1, xMax / 4, "|%12i|%12i|%12i|%12i|%12i|%12i|", static_cast<int>(Martin.getResource(0)), static_cast<int>(Martin.getResource(1)), static_cast<int>(Martin.getResource(2)), static_cast<int>(Martin.getResource(3)), static_cast<int>(Martin.getResource(4)), static_cast<int>(Martin.getResource(5)));
		box(win2, 0, 0);

		wrefresh(win[window]);
		wrefresh(win2);
	}
	keypad(win[0], 0);
	keypad(win[1], 0);

	endwin();

	return (0);
}