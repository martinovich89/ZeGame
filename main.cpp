#include "Realm.hpp"


std::string	resources[6] = {"Ore", "Gaz", "Pearl", "Aether", "Uranium", "Adamantium"};
int menu = 1;

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
}

int	display_arrow(int c, int width, int attr, int count, int newline)
{
	int offset = 3;
	static int arrow_x = 0;
	static int arrow_y = 0 + offset;

	if (c == 119 && arrow_y > 0 + offset)
	{
		mvprintw(arrow_y,arrow_x," ");
		arrow_y -= 2;
	}
	else if (c == 97 && arrow_x > 0)
	{
		mvprintw(arrow_y,arrow_x," ");
		arrow_x -= width / attr;
	}
	else if (c == 115 && arrow_y < newline * count + offset)
	{
		mvprintw(arrow_y,arrow_x," ");
		arrow_y += 2;
	}
	else if (c == 100 && arrow_x < static_cast<int>(static_cast<double>(attr - 1) * static_cast<double>(width / attr)))
	{
		mvprintw(arrow_y,arrow_x," ");
		arrow_x += width / attr;
	}
	else if (c == 101 && menu < 3 && arrow_y != offset)
	{
		menu = 2;
		return ((arrow_y - offset) / 2);
	}
	mvprintw(arrow_y,arrow_x,">");
	return (0);
}

int main(void)
{
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
	int ret;
	int	toDisplay;
//	int arrow_y = 0 + offset;
//	int arrow_x = 0;

	noecho();
	cbreak();
	timeout(1);
	while ((c = getch()) != 27)
	{
		display_player(Martin);

		Martin.updateResources();

		toDisplay = (ret != 0) ? ret : toDisplay;

		if (menu == 1)
		{
//			ret = display_arrow(c, TERM_WIDTH, SYSTEM_ATTRIBUTES, SYSTEM_ACCOUNT, GALAXY_MENU_NEWLINE);
			display_galaxy(bigMama);
			ret = display_arrow(c, TERM_WIDTH, SYSTEM_ATTRIBUTES, SYSTEM_ACCOUNT, GALAXY_MENU_NEWLINE);
			if (ret)
				clear();
		}
		else if (menu == 2)
		{
			display_system(bigMama.getSys(toDisplay - 1));
			ret = display_arrow(c, TERM_WIDTH, PLANET_ATTRIBUTES, bigMama.getSys(toDisplay - 1).getPlanetAmount(), SYSTEM_MENU_NEWLINE);
			if (ret)
				clear();
		}

		mvprintw(25,0,"");
		refresh();
	}

	endwin();
	return (0);
}