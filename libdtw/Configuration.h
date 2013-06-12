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
	static Configuration* init(std::string configPath);
	static Configuration* instance();
	std::string getHost()
	{
		return host;
	}
	int getPort()
	{
		return port;
	}
	std::string getDbName()
	{
		return dbName;
	}
	~Configuration();
	float getThreshold()
	{
		return threshold;
	}

private:
	Configuration(){initDefault();}
	Configuration(std::string configPath);

private:
	void initDefault();
	std::string host;
	int port;
	std::string dbName;
	float threshold;

	static Configuration*  _instance;
};

} /* namespace SignatureAuthLibrary */
#endif /* CONFIGURATION_H_ */
