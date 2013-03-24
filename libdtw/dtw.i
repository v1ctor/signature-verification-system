%module dtw
%include std_vector.i
%include dtw.h

%{
#include <vector>

#include "dtw.h"
%}

%rename (__eq__) signature::operator==();

namespace std
{
	%template(points) vector<point>;
}
