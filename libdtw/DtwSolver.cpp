#include "DtwSolver.h"

namespace SignatureAuthLibrary
{

bool DtwSolver::check(const vector< vector<int> >& firstSign, const vector< vector<int> >& secondSign)
{
    int N = firstSign.size();
    int M = secondSign.size();
    
    
    double** matrix = new double*[N];

    for (int i = 0; i<N; i++)
    {
	matrix[i] = new double[M];
	for (int j  = 0; j< M; j++)
	{
	    matrix[i][j] = sqrt( pow(firstSign[i][0] - secondSign[j][0], 2) + pow(firstSign[i][1] - secondSign[j][1], 2));
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
            //std::cout << matrix[i][j] << "\t\t\t";
        }
        //std::cout << std::endl;
    }

    vector< vector<int> > path;    
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
        vector<int> point;
        point.push_back(i);
        point.push_back(j);
        path.push_back(point);
    
    }
    while (i != 0 && j != 0);

    for (int i = 0; i<N; i++) {
	delete[] matrix[i];
    }
    delete[] matrix;

    return false;
}

}
