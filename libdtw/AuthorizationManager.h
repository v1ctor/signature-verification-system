#ifndef AUTHORIZATION_MANAGER_H_
#define AUTHORIZATION_MANAGER_H_

#include <string>
#include <vector>
#include "Configuration.h"
#include "MongoDbDataSource.h"
#include "DtwSolver.h"
#include "CanNotLoadSignatureException.h"

using std::string;

namespace SignatureAuthLibrary
{

class AuthorizationManager
{
public:
    AuthorizationManager(string config);
    int registry(long long uid, std::vector< std::vector<int> > firstSign, std::vector< std::vector<int> > secondSign);
    int authorize(long long uid, std::vector< std::vector<int> > sign);
    int delete_user(long long uid, std::vector< std::vector<int> > sign);
    int add_sign(long long uid, std::vector< std::vector<int> > sign);

private:
    DataSource* ds;
};

}

#endif //AUTHORIZATION_MANAGER_H_
