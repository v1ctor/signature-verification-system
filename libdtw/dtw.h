#ifndef DYNAMIC_TIME_WARPER_H
#define DYNAMIC_TIME_WARPER_H

#include <vector>

struct point
{
	point(){};
	point(int x, int y):x(x),y(y){};
	int x;
	int y;
};


class dtw
{
public:
	dtw();
	~dtw();
	static bool check(std::vector<point> first, std::vector<point> second);
	//void compare();
	//bool operator==()
};


#endif //DYNAMIC_TIME_WARPER_H

