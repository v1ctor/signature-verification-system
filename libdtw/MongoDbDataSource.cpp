/*
 * MongoDbDataSource.cpp
 *
 *  Created on: 13.04.2013
 *      Author: victor
 */

#include "MongoDbDataSource.h"

namespace SignatureAuthLibrary
{

bool MongoDbDataSource::connect()
{
	try
	{
		c = new mongo::DBClientConnection();
		c->connect(mongo::HostAndPort(config.getHost(), config.getPort()));
		return true;
	} catch (const mongo::DBException &e)
	{
		std::cerr << "caught " << e.what() << std::endl;
	}
	return false;
}

bool MongoDbDataSource::saveSignature(long long uid, const Signature& s)
{
	mongo::BSONObjBuilder builder;
	mongo::BSONObj signature = builder.append("uid", uid).append("points", s.toBson()).obj();

	c->insert(config.getDbName(), signature);
	return true;
}

Signature MongoDbDataSource::loadSignature(unsigned long uid)
{
	//std::auto_ptr<mongo::DBClientCursor> cursor = c->query(config.getDbName(), QUERY( "uid" << uid ));
}

MongoDbDataSource::~MongoDbDataSource()
{
}

} /* namespace SignatureAuthLibrary */
