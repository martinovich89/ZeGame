#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sys/time.h>
#include <vector>
#include <algorithm>

#define TERM_WIDTH 160
#define SYSTEM_ATTRIBUTES 4
#define SYSTEM_ACCOUNT 4
#define PLAYER_ATTRIBUTES 3
#define GALAXY_MENU_NEWLINE 2
#define PLANET_ATTRIBUTES 6
#define SYSTEM_MENU_NEWLINE 2

#define STARSIZE_MIN 0.4
#define STARSIZE_MAX 2.6

#define PLANETAMOUNT_MIN 5
#define PLANETAMOUNT_MAX 10

#define COMETSPAN_MIN 4.0
#define COMETSPAN_MAX 7.0

#define INCLUSIVE 1
#define INPUT_MAX_LEN 120

typedef size_t id;

//extern size_t userId;

time_t	get_time();

template<typename T>
T	my_random(const T &lowest, const T &highest)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	srand((unsigned)(tv.tv_sec * 1000000 + tv.tv_usec));
	return (lowest + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX/(highest - lowest))));
}
