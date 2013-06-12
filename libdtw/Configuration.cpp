/*
 * AbstractConfiguration.cpp
 *
 *  Created on: 13.04.2013
 *      Author: victor
 */

#include "Configuration.h"

namespace SignatureAuthLibrary
{

Configuration* Configuration::_instance = 0;

Configuration* Configuration::init(std::string configPath)
{
	_instance = new Configuration(configPath);
}

Configuration* Configuration::instance()
{
	if (!_instance)
	{
		_instance = new Configuration();
	}
	return _instance;
}

Configuration::Configuration(std::string configPath)
{
	Config config;
	try
	{
		config.readFile(configPath.data());
		const Setting& root = config.getRoot();

		const Setting& dataSourceConfig = root["dataSource"];
		dataSourceConfig.lookupValue("host", host);
		dataSourceConfig.lookupValue("port", port);
		dataSourceConfig.lookupValue("dbName", dbName);
		const Setting& dtwConfig = root["dtw"];
		dtwConfig.lookupValue("threshold", threshold);

	} catch (const FileIOException &fioex)
	{
		std::cerr << "I/O error while reading file." << std::endl;
		initDefault();
	} catch (const ParseException &pex)
	{
		std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
				<< " - " << pex.getError() << std::endl;
		initDefault();
	}
	catch(const SettingNotFoundException &nfex)
	{
		std::cerr << "No 'name' setting in configuration file." << std::endl;
	}
}

Configuration::~Configuration()
{
	if (!_instance)
	{
		delete _instance;
	}
}

void Configuration::initDefault()
{
	host = "localhost";
	port = 27017;
	dbName = "sal.users";
}

} /* namespace SignatureAuthLibrary */
