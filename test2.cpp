#include <iostream>
#include <vector>

class Menu
{
	private :

	public :
		int			        _arrow_x;
		int			        _arrow_y;
		std::vector<std::string>	_selectables;
		std::vector<std::string>	_displayables;
		std::vector<int>                _selected;
		Menu() {}
		~Menu() {}
		Menu(std::vector<std::string> &selectables, std::vector<std::string> &displayables)
        {
			_selectables = selectables;
			_displayables = displayables;
			_selected.push_back(0);
 		}

		std::vector<std::string> &pick_selectable();

		int	getArrowY();
		int	getArrowX();

		void	setArrowX(int x);
		void	setArrowY(int y);
};

int main(void)
{
    std::vector<std::string> sv1 {"hello"};
	std::vector<std::string> sv2 {"bye"};
	Menu first(sv1, sv2);
	std::cout << first._selectables.back() << std::endl;
	std::vector<Menu> menus;

	menus.push_back(first);
	menus.push_back(Menu(sv2, sv1));
	std::cout << menus.back()._selectables[0] << std::endl;
	std::cout << menus[0]._selectables[0] << std::endl;
	return (0);
}
