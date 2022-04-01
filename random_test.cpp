#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sys/time.h>

template<typename T>
T	my_random(const T &lowest, const T &highest)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	srand((unsigned)(tv.tv_sec * 1000000 + tv.tv_usec));
	return (lowest + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX/(highest - lowest))));
}

int main(void)
{
	std::cout << my_random(1.123123, 2.999999) << std::endl;

	return (0);
}