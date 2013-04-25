/*
 * DataSource.h
 *
 *  Created on: 13.04.2013
 *      Author: victor
 */

#ifndef DATASOURCE_H_
#define DATASOURCE_H_

#include "Signature.h"

namespace SignatureAuthLibrary
{

class DataSource
{
public:
	virtual bool connect()=0;
	virtual bool saveSignature(long long uid, const Signature& s)=0;
	virtual Signature loadSignature(long long uid)=0;
	virtual ~DataSource(){};
};

} /* namespace SignatureAuthLibrary */
#endif /* DATASOURCE_H_ */
