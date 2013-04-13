/*
 * AbstractConfiguration.h
 *
 *  Created on: 13.04.2013
 *      Author: victor
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <string>
#include <libconfig.h++>
#include <iostream>

using libconfig::Config;
using libconfig::Setting;
using libconfig::SettingNotFoundException;
using libconfig::FileIOException;
using libconfig::ParseException;

namespace SignatureAuthLibrary
{

class Configuration
{
public:
	Configuration(std::string configPath);
	virtual ~Configuration();
	std::string getHost()
	{
		return host;
	}
	int getPort()
	{
		return port;
	}
private:
	/*Configuration(const Configuration&);*/
	void initDefault();
	std::string host;
	int port;
};

} /* namespace SignatureAuthLibrary */
#endif /* CONFIGURATION_H_ */
