/*
 * MongoDbDataSource.cpp
 *
 *  Created on: 13.04.2013
 *      Author: victor
 */

#include "MongoDbDataSource.h"

namespace SignatureAuthLibrary
{

MongoDbDataSource::MongoDbDataSource() :
	c(new mongo::DBClientConnection())
{}

bool MongoDbDataSource::connect()
{
	try
	{
		c->connect(mongo::HostAndPort(Configuration::instance()->getHost(),
			Configuration::instance()->getPort()));
	} catch (const mongo::DBException &e)
	{
		std::cerr << "caught " << e.what() << std::endl;
		throw;
	}
}

int MongoDbDataSource::saveSignature(long long uid, const vector< vector<int> >& points) 
{
	mongo::BSONObjBuilder builder;
	mongo::BSONObj signature = builder.append("_id", uid).append("points",
			to_bson(points)).obj();
	c->insert(Configuration::instance()->getDbName(), signature);
	return 1;
}

vector< vector<int> > MongoDbDataSource::loadSignature(long long uid)
{
	mongo::BSONObjBuilder builder;
	mongo::BSONObj query = builder.append("_id", uid).obj();

	std::auto_ptr<mongo::DBClientCursor> cursor = c->query(Configuration::instance()->getDbName(),
		mongo::Query(query));

	vector< vector<int> > result;
	if (cursor->more())
	{
		mongo::BSONObj o = cursor->next();
		mongo::BSONObjIterator it(o.getObjectField("points"));

		while(it.more())
		{
			mongo::BSONObj bo = it.next().Obj();
			vector<int> point;
			point.push_back(bo.getField("x").Int());
			point.push_back(bo.getField("y").Int());
			result.push_back(point);
		}

		return result;
	}

	throw CanNotLoadSignatureException();
}

mongo::BSONArray MongoDbDataSource::to_bson(const vector< vector<int> >& points)
{
	mongo::BSONArrayBuilder bab;
	for (int i = 0; i < points.size(); i++)
	{
		mongo::BSONObjBuilder pointBuilder;
		mongo::BSONObj arr = pointBuilder.append("x", points[i][0]).append("y",
				points[i][1]).obj();
		bab.append(arr);
	}
	return bab.arr();
}



} /* namespace SignatureAuthLibrary */
