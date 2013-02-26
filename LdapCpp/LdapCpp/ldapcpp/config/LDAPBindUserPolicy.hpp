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
#ifndef LDAP_BIND_USER_POLICY_HPP__
#define LDAP_BIND_USER_POLICY_HPP__

#include <ldapcpp/exception/LDAPInvalidConfigurationException.hpp>
#include <string>

namespace ldapcpp {

/**
 * LDAPBindUserPolicy - this is a policy class for checking the bind user information
 * in the configuration class.
 */
template<class Configuration>
class LDAPBindUserPolicy {
public:

	/**
	 * Default class constructor
	 */
	LDAPBindUserPolicy() {
	}

	/**
	 * Enforces the checking policy for the bind user information.
	 * @param config Configuration instance.
	 * @throws LDAPInvalidConfigurationException if the the bind user is not compliant with the policy.
	 */
	void enforceBindUser(const Configuration& config) throw (LDAPInvalidConfigurationException) {
		
		std::string user = config.getBindUser();

		if(user.empty()) {
			throw LDAPInvalidConfigurationException("Bind user information not found");
		}
	}
protected:
	~LDAPBindUserPolicy() {
	}
};

}

#endif