/*
 * MongoDbDataSource.h
 *
 *  Created on: 13.04.2013
 *      Author: victor
 */

#ifndef MONGODBDATASOURCE_H_
#define MONGODBDATASOURCE_H_

#include "DataSource.h"
#include "Configuration.h"
#include "CanNotLoadSignatureException.h"

#include <mongo/client/dbclient.h>

#include <string>
#include <iostream>
#include <vector>
#include <memory>

using std::vector;

namespace SignatureAuthLibrary
{

class MongoDbDataSource: public DataSource
{
public:
	MongoDbDataSource();
	bool connect();
	int saveSignature(long long uid, const vector< vector<int> >& points);
	vector< vector<int> > loadSignature(long long uid);
	virtual ~MongoDbDataSource(){};
private:
	mongo::BSONArray to_bson(const vector< vector<int> >& points);

private:
	std::auto_ptr<mongo::DBClientConnection> c;
};

} /* namespace SignatureAuthLibrary */
#endif /* MONGODBDATASOURCE_H_ */
