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
	Fev-09-2010		andersonkmi			Initial version.
******************************************************************************/
#ifndef LDAP_SERVER_ADDR_POLICY_HPP__
#define LDAP_SERVER_ADDR_POLICY_HPP__

#include <ldapcpp/exception/LDAPInvalidConfigurationException.hpp>
#include <ldapcpp/config/LDAPServerAddrRule.hpp>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

namespace ldapcpp {

/**
 * LDAPServerAddrPolicy - this is a policy class responsible for validating the 
 * LDAP servers informed in the configuration.
 */
template<class Configuration>
class LDAPServerAddrPolicy {
public:
	/**
	 * Default class constructor
	 */ 
	LDAPServerAddrPolicy() {
	}

	/**
	 * Enforces the server address policy - there should be no blank server addresses.
	 * @param config Configuration information.
	 * @throws LDAPInvalidConfigurationException if empty server address is found.
	 */
	void enforceServerAddr(const Configuration& config) throw (LDAPInvalidConfigurationException) {		
		std::vector<std::string> servers = config.getServers();		
		if(servers.empty()) {
			throw LDAPInvalidConfigurationException("Missing LDAP servers in configuration");
		}

		LDAPServerAddrRule rule;
		std::for_each(servers.begin(), servers.end(), rule);
	}
protected:
	~LDAPServerAddrPolicy() {
	}
};

}

#endif