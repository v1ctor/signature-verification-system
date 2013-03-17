#include "dtw.h"
#include <iostream>

dtw::dtw()
{
	std::cout << "ctor" << std::endl;
}

bool dtw::check(std::vector<point> first, std::vector<point> second)
{
	for (int i=0; i < first.size(); i++)
	{
		std::cout << first[i].x << " " << first[i].y << std::endl;
	}

	for (int i=0; i < second.size(); i++)
	{
		std::cout << second[i].x << " " << second[i].y << std::endl;
	}
}

dtw::~dtw()
{
	std::cout << "dtor" << std::endl;
}
