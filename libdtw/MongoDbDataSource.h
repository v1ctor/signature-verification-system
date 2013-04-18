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

#include <mongo/client/dbclient.h>

#include <string>
#include <iostream>
#include <vector>
#include <memory>

namespace SignatureAuthLibrary
{

class MongoDbDataSource: public DataSource
{
public:
	MongoDbDataSource(Configuration& config) : config(config){};
	bool connect();
	bool saveSignature(long long uid, const Signature& s);
	Signature loadSignature(unsigned long uid);
	virtual ~MongoDbDataSource();
private:
	Configuration& config;
	mongo::DBClientConnection* c;
};

} /* namespace SignatureAuthLibrary */
#endif /* MONGODBDATASOURCE_H_ */
