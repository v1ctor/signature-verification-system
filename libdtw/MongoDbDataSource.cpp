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
		c.connect(mongo::HostAndPort(config.getHost(), config.getPort()));
		return true;
	} catch (const mongo::DBException &e)
	{
		std::cerr << "caught " << e.what() << std::endl;
	}
}

bool MongoDbDataSource::saveSignature(long long uid, const Signature& s)
{
	mongo::BSONObjBuilder builder;
	builder.append("uid", uid);
//	const std::vector<Point>& points = s.getPoints();
//	for (int i = 0; i<points.size(); i++) {
//
//	}

}

Signature MongoDbDataSource::loadSignature(unsigned long uid)
{

}

MongoDbDataSource::~MongoDbDataSource()
{
	// TODO Auto-generated destructor stub
}
} /* namespace SignatureAuthLibrary */
