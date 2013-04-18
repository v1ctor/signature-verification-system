/*
 * Signature.cpp
 *
 *  Created on: 13.04.2013
 *      Author: victor
 */

#include "Signature.h"

namespace SignatureAuthLibrary
{

Signature::Signature(std::vector<Point>& p)
{
	points = p;
}

Signature::~Signature()
{
	// TODO Auto-generated destructor stub
}

bool Signature::operator==(const Signature& s) const
{
	for (int i = 0; i < points.size(); i++)
	{
		std::cout << points[i].x << " " << points[i].y << std::endl;
	}

	for (int i = 0; i < s.points.size(); i++)
	{
		std::cout << s.points[i].x << " " << s.points[i].y << std::endl;
	}

	//TODO compare
	return false;
}

mongo::BSONArray Signature::toBson() const
{
	mongo::BSONArrayBuilder bab;
	for (int i = 0; i < points.size(); i++)
	{
		mongo::BSONObjBuilder pointBuilder;
		mongo::BSONObj arr = pointBuilder.append("x", points[i].x).append("y",
				points[i].y).obj();
		bab.append(arr);
	}
	return bab.arr();
}

} /* namespace SignatureAuthLibrary */
