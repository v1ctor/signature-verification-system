#ifndef DYNAMIC_TIME_WARPER_H
#define DYNAMIC_TIME_WARPER_H

#include <vector>
#include <iostream>

struct point
{
	point(){};
	point(int x, int y):x(x),y(y){};
	int x;
	int y;
};


class signature
{
public:
	signature(std::vector<point>& p);
	~signature();
	bool operator==(signature const & s) const;

private:
	std::vector<point> points;
};
#endif //DYNAMIC_TIME_WARPER_H
