/*
 * Signature.h
 *
 *  Created on: 13.04.2013
 *      Author: victor
 */

#ifndef SIGNATURE_H_
#define SIGNATURE_H_

#include <vector>
#include <iostream>
#include <mongo/client/dbclient.h>
#include <math.h>

namespace SignatureAuthLibrary
{

struct Point
{
	Point(){};
	Point(int x, int y) : x(x), y(y) {};
	int x;
	int y;
};

class Signature
{
public:
	Signature(){};
	Signature(std::vector<Point>& p);
	Signature(const mongo::BSONElement& be);

	bool operator==(Signature const & s) const;
	const Point& operator[](int index) const;

	const std::vector<Point>& getPoints() { return points; }
	void append(Point p) {points.push_back(p);}
	mongo::BSONArray toBson() const;
	virtual ~Signature();

private:
	std::vector<Point> points;
};

} /* namespace SignatureAuthLibrary */
#endif /* SIGNATURE_H_ */
