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
#ifndef LDAP_BIND_PASSWORD_POLICY_HPP__
#define LDAP_BIND_PASSWORD_POLICY_HPP__

#include <ldapcpp/exception/LDAPInvalidConfigurationException.hpp>
#include <string>

namespace ldapcpp {

/**
 * LDAPBindPasswordPolicy - this a policy class used to check the bind password in the configuration.
 */
template <class Configuration>
class LDAPBindPasswordPolicy {
public:

	/**
	 * Default class constructor.
	 */
	LDAPBindPasswordPolicy() {
	}

	/**
	 * Enforces the bind password policy - it must not be empty.
	 * @param config Configuration instance.
	 * @throws LDAPInvalidConfigurationException if the bind password is blank.
	 */
	void enforceBindPassword(const Configuration& config) throw (LDAPInvalidConfigurationException) {
	
		std::string password = config.getBindPwd();
		if(password.empty()) {
			throw LDAPInvalidConfigurationException("Missing bind user password.");
		}
	}
protected:
	~LDAPBindPasswordPolicy() {
	}
};

}

#endif