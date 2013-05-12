/*
 * DataSource.h
 *
 *  Created on: 13.04.2013
 *      Author: victor
 */

#ifndef DATASOURCE_H_
#define DATASOURCE_H_

#include <vector>

using std::vector;

namespace SignatureAuthLibrary
{

class DataSource
{
public:
	virtual bool connect()=0;
	virtual int saveSignature(long long uid, const vector< vector<int> >& points)=0;
	virtual vector< vector<int> > loadSignature(long long uid)=0;
	virtual ~DataSource(){};
};

} /* namespace SignatureAuthLibrary */
#endif /* DATASOURCE_H_ */
