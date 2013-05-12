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
	int N = points.size();
	int M = s.points.size();
	
	
	double** matrix = new double*[N];

	for (int i = 0; i<N; i++)
	{
		matrix[i] = new double[M];
		for (int j  = 0; j< M; j++)
		{
			matrix[i][j] = sqrt( pow(points[i].x - s[j].x, 2) + pow(points[i].y - s[j].y, 2));
		}
	}

    for (int i=1; i<N; i++)
    	matrix[i][0] += matrix[i-1][0];

    for (int i=1; i<M; i++)
    	matrix[0][i] += matrix[0][i-1];

    for (int i=1; i<N; i++ )
    {
        for (int j=1; j<M; j++)
        {
            matrix[i][j] += std::min(matrix[i-1][j-1], std::min(matrix[i-1][j], matrix[i][j-1]));
            std::cout << matrix[i][j] << "\t\t\t";
        }
        std::cout << std::endl;
    }

	std::vector<Point> path;    
    {
		int i = N-1;
		int j = M-1;
		do
		{
			 double diagCost;
			 double leftCost;
			 double downCost;

			 if ((i>0) && (j>0))
				diagCost = matrix[i-1][j-1];
			 else
				diagCost = DBL_MAX;

			 if (i > 0)
				leftCost = matrix[i-1][j];
			 else
				leftCost = DBL_MAX;

			 if (j > 0)
				downCost = matrix[i][j-1];
			 else
				downCost = DBL_MAX;
				
			 if ((diagCost<=leftCost) && (diagCost<=downCost))
			 {
				i--;
				j--;
			 }
			 else if ((leftCost<diagCost) && (leftCost<downCost))
				i--;
			 else if ((downCost<diagCost) && (downCost<leftCost))
				j--;
			 else if (i <= j)
				j--;
			 else
				i--;
			path.push_back(Point(i, j));
		
		}
		while (i != 0 && j != 0);
	}
	for (int i =0 ; i<path.size(); i++) 
	{
		std::cout << path[i].x << " " << path[i].y << std::endl;
	}
	
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
