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

Signature::Signature(const mongo::BSONElement& be)
{
	//std::vector<mongo::BSONElement> elements = be.Array();
}

Signature::~Signature()
{
	// TODO Auto-generated destructor stub
}

bool Signature::operator==(const Signature& s) const
{
	double** matrix = new double*[points.size()];

	for (int i = 0; i<points.size(); i++)
	{
		matrix[i] = new double[s.points.size()];
		for (int j  = 0; j< s.points.size(); j++)
		{
			matrix[i][j] = sqrt( pow(points[i].x - s[i].x, 2) + pow(points[i].y - s[i].y, 2));
		}
	}

    for (int i=1; i<points.size(); i++)
    	matrix[i][0] += matrix[i-1][0];

    for (int i=1; i<s.points.size(); i++)
    	matrix[0][i] += matrix[0][i-1];

    for (int i=1; i<points.size(); i++ )
    {
        for (int j=1; j<s.points.size(); j++)
        {
            //array[i][j] += (array[i-1][j-1] < array[i-1][j]) ? array[i-1][j-1] :((array[i-1][j] < array[i][j-1]) ? array[i-1][j] : array[i][j-1]);
            std::cout << matrix[i][j] << "\t\t\t";
        }
        std::cout << std::endl;
    }

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

const Point& Signature::operator [](int index) const
{
	return points[index];
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
