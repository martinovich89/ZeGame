#pragma once

#include "Utils.hpp"
#include <iostream>
#define PEARL 0
#define AETHER 1
#define URANIUM 2
#define ADAMANTIUM 3

class Comet
{
	private :
		double	_size;
		int		_resourceType;
		int		_destination;
	
	public :
		Comet();
		~Comet();
		Comet(const Comet &other);
		Comet &operator=(const Comet &other);

		Comet(double size, int resourceType, int destination);
};