#include "dtw.h"




signature::signature(std::vector<point>& p)
{
	points = p;
	std::cout << "ctor" << std::endl;
}

bool signature::operator==(signature const & s) const
{	
	for (int i=0; i < points.size(); i++)
	{
		std::cout << points[i].x << " " << points[i].y << std::endl;
	}

	for (int i=0; i < s.points.size(); i++)
	{
		std::cout << s.points[i].x << " " << s.points[i].y << std::endl;
	}
}

signature::~signature()
{
	std::cout << "dtor" << std::endl;
}
