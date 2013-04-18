/*
 * AbstractConfiguration.cpp
 *
 *  Created on: 13.04.2013
 *      Author: victor
 */

#include "Configuration.h"

namespace SignatureAuthLibrary
{

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
	// TODO Auto-generated destructor stub
}

void Configuration::initDefault()
{
	host = "localhost";
	port = 27017;
	dbName = "sal.users";
}

} /* namespace SignatureAuthLibrary */

