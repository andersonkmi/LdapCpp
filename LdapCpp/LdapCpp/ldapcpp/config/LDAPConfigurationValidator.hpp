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
	Sep-27-2010		andersonkmi			Inserted logging code.
******************************************************************************/
#ifndef LDAP_CONFIGURATION_VALIDATOR_HPP__
#define LDAP_CONFIGURATION_VALIDATOR_HPP__

#include <ldapcpp/exception/LDAPInvalidConfigurationException.hpp>
#include <ldapcpp/config/LDAPConfigurationManager.hpp>

namespace ldapcpp {

/**
 * LDAPConfigurationValidator - this a policy class that will validate the configuration information using
 * isolated policy classes supplied to it. This implementation was based on the policy class technique
 * described in the book "Modern C++ design" by Andrei Alexandrescu. For more details, take a look at
 * the chapter 1 - Policy based class design (page 3).
 */
template<class Configuration, class VendorPolicy, class ServerPolicy, class PortPolicy, class BaseDNPolicy, class BindUserPolicy, class BindPwdPolicy, class TimeoutPolicy>
class LDAPConfigurationValidator : public VendorPolicy, public ServerPolicy, public PortPolicy, public BaseDNPolicy, public BindUserPolicy, public BindPwdPolicy, public TimeoutPolicy {

public:
	/**
	 * Default class constructor.
	 */
	LDAPConfigurationValidator() {

	}

	~LDAPConfigurationValidator() {

	}

	/**
	 * Validates the configuration information delegating the checking details to the policy classes
	 * passed to the template initialization.
	 * @param config Configuration instance.
	 * @throws LDAPInvalidConfigurationException if a problem with the configuration is found.
	 */
	void validate(const Configuration& config) throw (LDAPInvalidConfigurationException) {		

		VendorPolicy::enforceServerVendor(config);
		ServerPolicy::enforceServerAddr(config);
		PortPolicy::enforcePort(config);
		BaseDNPolicy::enforceBaseDN(config);
		BindUserPolicy::enforceBindUser(config);
		BindPwdPolicy::enforceBindPassword(config);
		TimeoutPolicy::enforceTimeout(config);
		//GroupBaseDNPolicy::enforceGroupBaseDN(config);
	}
};

}

#endif
