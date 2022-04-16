#include <iostream>
#include <vector>
#include <string>

class Slot
{
	private :
		std::string					_name;
		int							_type;
		int							_level;
		std::vector<std::string>	_selectables;

	public :
		Slot();
		~Slot();
		
		void	build(int n);

		std::string getName() const;
		int getType() const;
		int getLevel() const;
		std::vector<std::string> &getSelectables();

		void	setName(const std::string &name);
		void	setType(const int _type);
		void	setLevel(const int _level);
};