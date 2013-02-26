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
#ifndef LDAP_TIMEOUT_POLICY_HPP__
#define LDAP_TIMEOUT_POLICY_HPP__

#include <ldapcpp/exception/LDAPInvalidConfigurationException.hpp>
#include <sstream>

namespace ldapcpp {

/**
 * LDAPTimeoutPolicy - this is a policy class responsible for validating the timeout
 * information in the configuration.
 */
template<class Configuration>
class LDAPTimeoutPolicy {
public:
	/**
	 * Default class constructor.
	 */ 
	LDAPTimeoutPolicy() {
	}

	/**
	 * Validates the policy for the timeout configuration.
	 * @param config Configuration instance.
	 * @throws LDAPInvalidConfigurationException if the timeout information is not valid.
	 */
	void enforceTimeout(const Configuration& config) throw (LDAPInvalidConfigurationException) {
		unsigned int timeout = config.getTimeout();
		if(timeout > 120) {
			throw LDAPInvalidConfigurationException("Timeout is way higher than 120 seconds");
		}
	}
protected:
	~LDAPTimeoutPolicy() {
	}
};

}

#endif