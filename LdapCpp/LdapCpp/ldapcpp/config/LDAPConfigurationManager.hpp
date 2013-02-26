/******************************************************************************
	LDAPCpp - LDAP wrapper library for C++
	Copyright (C) 2010  Anderson Ito (andersonkmi@acm.org)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/
/******************************************************************************
	Modification history
	====================

	Date			Author				Description
	====			======				===========
	Fev-04-2010		andersonkmi			Initial version.
	Sep-25-2010		andersonkmi			Added support for group searching.
******************************************************************************/
#ifndef LDAP_CONFIGURATION_MANAGER_HPP__
#define LDAP_CONFIGURATION_MANAGER_HPP__

#ifdef LDAP_CPP_EXPORTS
#define LDAP_CPP_API __declspec(dllexport)
#else
#define LDAP_CPP_API __declspec(dllimport)
#endif

#include <string>
#include <vector>

#pragma warning (disable: 4251)

namespace ldapcpp {

/**
 * LDAPConfigurationManager - this class is used to hold the connection information
 * required to access a LDAP server.
 */
class LDAP_CPP_API LDAPConfigurationManager {
public:

	/**
	 * Constants representing the supported LDAP servers.
	 */
	static const std::string APACHE_DIR_SERVER;
	static const std::string MS_ACTIVE_DIRECTORY_2000;
	static const std::string MS_ACTIVE_DIRECTORY_2003;

	/**
	 * Default class constructor. It initializes all field members with default values.
	 * String field members are initialized with blank values. Integer numbers are
	 * initialized with zero and lists are initially empty. The SSL option is set to false
	 * by default.
	 */
	LDAPConfigurationManager();

	/**
	 * Copy-constructor.
	 */
	LDAPConfigurationManager(const LDAPConfigurationManager& rhs);

	/**
	 * Operator assignment.
	 */
	LDAPConfigurationManager& operator=(const LDAPConfigurationManager& rhs);
	virtual ~LDAPConfigurationManager();

	/**
	 * Sets the server vendor information in the configuration.
	 * @param vendor String containing the vendor information.
	 * The valid values are the ones represented by the constants in this class.
	 */
	void setServerVendor(const std::string& vendor);
	
	/**
	 * Adds an LDAP server address into the configuration.
	 * @param server String containing the server name or address.
	 */
	void addServer(const std::string& server);

	/**
	 * Sets the LDAP connection port information.
	 @param port Integer number representing the connection port.
	 */
	void setPort(unsigned int port);
	
	/**
	 * Adds a base DN into the configuration.
	 * @param baseDN String containing a base DN to be used during LDAP search.
	 */
	void addBaseDN(const std::string& baseDN);

	/**
	 * Adds a group base DN into the configuration.
	 * @param groupBaseDN String containing a group base DN to be used during LDAP search.
	 */
	void addGroupBaseDN(const std::string& groupBaseDN);

	/**
	 * Sets the bind user information.
	 * @param bind String containing the bind user.
	 */
	void setBindUser(const std::string& bind);

	/**
	 * Sets the bind user's password information.
	 * @param pwd String containing the bind user's password.
	 */
	void setBindPwd(const std::string& pwd);

	/**
	 * Sets the connection timeout in seconds.
	 * @param timeout Integer number representing the timeout for LDAP connection process.
	 */
	void setTimeout(unsigned int timeout);

	/**
	 * Sets the SSL option for LDAP connection.
	 * @param flag Boolean value to indicate whether or not to enable SSL connection.
	 */
	void setEnableSSL(bool flag);

	/**
	 * Returns the server vendor information currently configured.
	 * @return String containing the server vendor information.
	 */
	virtual std::string getServerVendor() const;

	/**
	 * Returns the server vendor information currently configured.
	 * @return String containing the server vendor information.
	 */
	virtual std::string getServerVendor();

	/**
	 * Returns the connection port number currently configured.
	 * @return Integer number holding the connection port.
	 */
	virtual unsigned int getPort() const;
	
	/**
	 * Returns the connection port number currently configured.
	 * @return Integer number holding the connection port.
	 */	
	virtual unsigned int getPort();

	/**
	 * Returns the bind user name currently configured.
	 * @return String holding the bind user.
	 */	
	virtual std::string getBindUser() const;

	/**
	 * Returns the bind user name currently configured.
	 * @return String holding the bind user.
	 */	
	virtual std::string getBindUser();

	/**
	 * Returns the bind user password currently configured.
	 * @return String holding the bind user password.
	 */	
	virtual std::string getBindPwd() const;

	/**
	 * Returns the bind user password currently configured.
	 * @return String holding the bind user password.
	 */	
	virtual std::string getBindPwd();

	/**
	 * Returns the connection timeout (in seconds) currently configured.
	 * @return Integer number holding the timeout information.
	 */	
	virtual unsigned int getTimeout() const;
	
	/**
	 * Returns the connection timeout (in seconds) currently configured.
	 * @return Integer number holding the timeout information.
	 */	
	virtual unsigned int getTimeout();

	/**
	 * Returns a flag indicating if SSL connections are enabled (true) or not (false).
	 * @return Boolean indicating of SSL is enabled.
	 */	
	virtual bool isSSLEnabled() const;

	/**
	 * Returns a flag indicating if SSL connections are enabled (true) or not (false).
	 * @return Boolean indicating of SSL is enabled.
	 */	
	virtual bool isSSLEnabled();

	/**
	 * Returns a list of LDAP servers to connect.
	 * @return List of strings holding the server names or addresses.
	 */	
	virtual std::vector<std::string> getServers() const;

	/**
	 * Returns a list of LDAP servers to connect.
	 * @return List of strings holding the server names or addresses.
	 */
	virtual std::vector<std::string> getServers();

	/**
	 * Returns a list of base DNs to be used in search operations.
	 * @return List of strings holding the base DNs currently configured.
	 */
	virtual std::vector<std::string> getBaseDNs() const;
	
	/**
	 * Returns a list of base DNs to be used in search operations.
	 * @return List of strings holding the base DNs currently configured.
	 */	
	virtual std::vector<std::string> getBaseDNs();

	virtual std::vector<std::string> getGroupBaseDNs() const;
	virtual std::vector<std::string> getGroupBaseDNs();
private:
	std::string serverVendor_;
	std::vector<std::string> servers_;
	unsigned int port_;
	std::vector<std::string> baseDNs_;
	std::vector<std::string> groupBaseDNs_;
	std::string bindUser_;
	std::string bindPwd_;
	unsigned int timeout_;
	bool enableSSL_;
};

}

#endif
