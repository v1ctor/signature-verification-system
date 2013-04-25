/*
 * CanNotLoadSignatureException.h
 *
 *  Created on: 21.04.2013
 *      Author: victor
 */

#include <exception>

#ifndef CANNOTLOADSIGNATUREEXCEPTION_H_
#define CANNOTLOADSIGNATUREEXCEPTION_H_

namespace SignatureAuthLibrary
{

class CanNotLoadSignatureException  : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Can not load signature!";
	}
};

} /* namespace SignatureAuthLibrary */
#endif /* CANNOTLOADSIGNATUREEXCEPTION_H_ */
