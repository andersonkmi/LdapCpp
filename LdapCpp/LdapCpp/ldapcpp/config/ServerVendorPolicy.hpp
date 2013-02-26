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
	Sep-28-2010		andersonkmi			Inserted logging code.
******************************************************************************/
#ifndef SERVER_VENDOR_POLICY_HPP__
#define SERVER_VENDOR_POLICY_HPP__

#include <string>
#include <sstream>
#include <ldapcpp/exception/LDAPInvalidConfigurationException.hpp>

namespace ldapcpp {
/**
 * ServerVendorPolicy - this is a policy class responsible for validating the server vendor
 * information.
 */
template<class Configuration>
class ServerVendorPolicy {
public:
	/**
	 * Default class constructor
	 */
	ServerVendorPolicy() {

	}

	/**
	 * Validates the server vendor information in the configuration.
	 * @param config Configuration instance.
	 * @throws LDAPInvalidConfigurationException if the server vendor information is missing or out of the expected domain values.
	 */
	void enforceServerVendor(const Configuration& config) throw (LDAPInvalidConfigurationException) {
		std::string serverVendor = config.getServerVendor();
		if(serverVendor.empty()) {
			throw LDAPInvalidConfigurationException("Server vendor information not found");
		} else if(serverVendor.compare("ApacheDS") != 0 && serverVendor.compare("AD2000") != 0 && serverVendor.compare("AD2003") != 0) {
			std::ostringstream message;
			message << "Invalid server vendor configured: " << serverVendor;
			throw LDAPInvalidConfigurationException(message.str());
		}
	}
protected:
	~ServerVendorPolicy() {

	}
};

}

#endif