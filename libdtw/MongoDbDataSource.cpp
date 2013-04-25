/*
 * MongoDbDataSource.cpp
 *
 *  Created on: 13.04.2013
 *      Author: victor
 */

#include "MongoDbDataSource.h"

namespace SignatureAuthLibrary
{

MongoDbDataSource::MongoDbDataSource(Configuration& config) :
		config(config), c(new mongo::DBClientConnection())
{
}

bool MongoDbDataSource::connect()
{
	try
	{
		c->connect(mongo::HostAndPort(config.getHost(), config.getPort()));
	} catch (const mongo::DBException &e)
	{
		std::cerr << "caught " << e.what() << std::endl;
		throw;
	}
}

bool MongoDbDataSource::saveSignature(long long uid, const Signature& s)
{
	mongo::BSONObjBuilder builder;
	mongo::BSONObj signature = builder.append("uid", uid).append("points",
			s.toBson()).obj();
	c->insert(config.getDbName(), signature);
	return true;
}

Signature MongoDbDataSource::loadSignature(long long uid)
{
	mongo::BSONObjBuilder builder;
	mongo::BSONObj query = builder.append("uid", uid).obj();

	std::auto_ptr<mongo::DBClientCursor> cursor = c->query(config.getDbName(), mongo::Query(query));

	Signature result;
	if (cursor->more())
	{
		mongo::BSONObj o = cursor->next();
		mongo::BSONObjIterator it(o.getObjectField("points"));

		while(it.more())
		{
			mongo::BSONObj point = it.next().Obj();
			result.append(Point(point.getField("x").Int(), point.getField("y").Int()));
		}

		return result;
	}

	throw CanNotLoadSignatureException();
}

MongoDbDataSource::~MongoDbDataSource()
{
}

} /* namespace SignatureAuthLibrary */
