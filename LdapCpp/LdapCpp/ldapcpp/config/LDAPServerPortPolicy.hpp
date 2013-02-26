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
#ifndef LDAP_SERVER_PORT_POLICY_HPP__
#define LDAP_SERVER_PORT_POLICY_HPP__

#include <ldapcpp/exception/LDAPInvalidConfigurationException.hpp>
#include <sstream>
#include <string>

namespace ldapcpp {

/**
 * LDAPServerPortPolicy - this is a policy class responsible for validating the LDAP
 * server port information in the configuration.
 */
template<class Configuration>
class LDAPServerPortPolicy {
public:
	/**
	 * Default class constructor
	 */
	LDAPServerPortPolicy() {
	}

	/**
	 * Validates the server port information.
	 * @param config Configuration instance.
	 * @throws LDAPInvalidConfigurationException if the server port is invalid.
	 */
	void enforcePort(const Configuration& config) throw (LDAPInvalidConfigurationException) {
		unsigned int port = config.getPort();

		if(port <= 0) {
			std::ostringstream message;
			message << "Invalid port number: " << port;
			throw LDAPInvalidConfigurationException(message.str());
		}
	}
protected:
	~LDAPServerPortPolicy() {
	}
};

}

#endif