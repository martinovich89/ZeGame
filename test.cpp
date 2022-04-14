#include <iostream>
#include <vector>

class Test
{
	public :
		std::vector<std::string> sv1;
		std::vector<std::string> sv2;
		std::vector<int> iv;

		Test() : sv1(), sv2(), iv() { sv1.push_back("hello"); sv2.push_back("bye"); iv.push_back(1); }
		Test(std::vector<std::string> &v1, std::vector<std::string> &v2) : sv1(), sv2(), iv() { sv1 = v1; sv2 = v2; iv.push_back(1); }
};

int main(void)
{
	std::vector<std::string> v1 {"bonjour", "salut"};
	std::vector<std::string> v2 {"hello", "bye"};
	Test test(v1, v2);
	std::vector<Test> v;
	v.push_back(test);
	std::cout << v.back().sv1.back() << std::endl;
	std::cout << v.back().sv2.back() << std::endl;

	v.back().iv.back()++;

	std::cout << v.back().iv.back() << std::endl;
	return (0);
}
