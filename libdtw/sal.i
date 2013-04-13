%module sal

%{
#include <vector>
#include "libconfig.h++"
#include "Configuration.h"
#include "Signature.h"
#include "DataSource.h"
#include "MongoDbDataSource.h"

%}

%include std_vector.i
%include std_string.i
%include Configuration.h
%include Signature.h
%include DataSource.h
%include MongoDbDataSource.h


%rename (__eq__) SignatureAuthLibrary::Signature::operator==();

namespace std
{
	%template(Points) vector<SignatureAuthLibrary::Point>;
}
