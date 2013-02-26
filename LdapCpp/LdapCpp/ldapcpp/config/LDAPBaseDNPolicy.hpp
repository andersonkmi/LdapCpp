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
#ifndef LDAP_BASE_DN_POLICY_HPP__
#define LDAP_BASE_DN_POLICY_HPP__

#include <ldapcpp/exception/LDAPInvalidConfigurationException.hpp>
#include <ldapcpp/config/LDAPBaseDNRule.hpp>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

namespace ldapcpp {

/**
 * LDAPBaseDNPolicy - template class for handling a policy for checking the base DN
 * information in the configuration.
 */
template<class Configuration>
class LDAPBaseDNPolicy {
public:

	/**
	 * Default class constructor
	 */
	LDAPBaseDNPolicy() {
	}

	/**
	 * Enforce the policy for the base DN configuration information.
	 * @param config Configuration instance supplied in the class.
	 * @throws LDAPInvalidConfigurationException if the base DN is empty or if any of the items are blank strings.
	 */
	void enforceBaseDN(const Configuration& config) throw (LDAPInvalidConfigurationException) {
	
		std::vector<std::string> baseDNs = config.getBaseDNs();
		if(baseDNs.empty()) {
			throw LDAPInvalidConfigurationException("No base DNs found.");
		}

		LDAPBaseDNRule rule;
		std::for_each(baseDNs.begin(), baseDNs.end(), rule);
	}
protected:
	~LDAPBaseDNPolicy() {
	}
};

}

#endif