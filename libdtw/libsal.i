%module libsal %{
#include <vector>
#include "AuthorizationManager.h"
%}
%include std_vector.i
%include std_string.i
%include AuthorizationManager.h
namespace std {
    %template(Vector) vector<int>;
    %template(Matrix) vector< vector<int> >;
}
