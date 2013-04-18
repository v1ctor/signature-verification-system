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
	Signature(std::vector<Point>& p);
	bool operator==(Signature const & s) const;
	const std::vector<Point>& getPoints() { return points; }
	mongo::BSONArray toBson() const;
	virtual ~Signature();

private:
	std::vector<Point> points;
};

} /* namespace SignatureAuthLibrary */
#endif /* SIGNATURE_H_ */
