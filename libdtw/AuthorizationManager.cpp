#include "AuthorizationManager.h"

namespace SignatureAuthLibrary
{

AuthorizationManager::AuthorizationManager(std::string config)
{
    Configuration::init(config);
    ds = new MongoDbDataSource();
    ds->connect();
}

int AuthorizationManager::registry(long long uid, std::vector< std::vector<int> > firstSign, std::vector< std::vector<int> > secondSign)
{
    return ds->saveSignature(uid, secondSign);
}

int AuthorizationManager::authorize(long long uid, std::vector< std::vector<int> > sign)
{
    std::vector< std::vector<int> > target;
    try
    {
        target = ds->loadSignature(uid);
    }
    catch (const CanNotLoadSignatureException& e)
    {
        return -2;
    }
    if (DtwSolver::check(target, sign))
    {
        return 1;
    }
    else
    {
        return -1; //TODO Add enum -2, -1, 1
    }
    
}
    
int AuthorizationManager::delete_user(long long uid, std::vector< std::vector<int> > sign){ return -1; }
int AuthorizationManager::add_sign(long long uid, std::vector< std::vector<int> > sign){ return -1; }

}
