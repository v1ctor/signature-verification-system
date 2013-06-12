#ifndef DTW_SOLVER_H_
#define DTW_SOLVER_H_

#include <vector>
#include <math.h>
#include <algorithm>
#include <float.h>
#include <iostream>

#include "Configuration.h"

using std::vector;

namespace SignatureAuthLibrary
{

class DtwSolver
{
public:
	static bool check(const vector< vector<int> >& firstSign, const vector< vector<int> >& secondSign);
};

} /* namespace SignatureAuthLibrary */
#endif /* DTW_SOLVER_H_ */
