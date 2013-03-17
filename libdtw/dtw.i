%module dtw
%include std_vector.i
%include dtw.h

%{
#include <vector>

#include "dtw.h"
%}

namespace std
{
	%template(vectorPoint) vector<point>;
}


