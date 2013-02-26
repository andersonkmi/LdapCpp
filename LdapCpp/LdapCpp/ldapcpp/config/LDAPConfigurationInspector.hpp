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
	Sep-27-2010		andersonkmi			Logging code included.
******************************************************************************/
#ifndef LDAP_CONFIGURATION_INSPECTOR_HPP__
#define LDAP_CONFIGURATION_INSPECTOR_HPP__

#ifdef LDAP_CPP_EXPORTS
#define LDAP_CPP_API __declspec(dllexport)
#else
#define LDAP_CPP_API __declspec(dllimport)
#endif

#include <ldapcpp/exception/LDAPInvalidConfigurationException.hpp>
#include <ldapcpp/config/LDAPConfigurationManager.hpp>

#pragma warning (disable: 4290)

namespace ldapcpp {

/**
 * LDAPConfigurationInspector - this class is responsible for validating the 
 * provided configuration information held by LDAPConfigurationManager instance.
 */
class LDAP_CPP_API LDAPConfigurationInspector {
public:
	/**
	 * Default class constructor.
	 */
	LDAPConfigurationInspector();
	virtual ~LDAPConfigurationInspector();

	/**
	 * Inspects the configuration information provided by LDAPConfigurationManager instance.
	 * @param config Instance of <code>LDAPConfigurationManager</code> class.
	 * @throws LDAPInvalidConfigurationException if there is an error with the configuration.
	 * For more details on the possible errors, check the LDAPConfigurationValidator and its related
	 * policy classes.
	 * @see LDAPConfigurationValidator
	 * @see LDAPBaseDNPolicy
	 * @see LDAPBindPasswordPolicy
	 * @see LDAPBindUserPolicy
	 * @see LDAPServerAddrPolicy
	 * @see LDAPServerPortPolicy
	 * @see LDAPTimeoutPolicy
	 * @see ServerVendorPolicy
	 */
	virtual void inspect(const LDAPConfigurationManager& config) throw (LDAPInvalidConfigurationException);
private:

	// Disabled copy-ctor and operator assignment
	LDAPConfigurationInspector(const LDAPConfigurationInspector&);
	LDAPConfigurationInspector& operator=(const LDAPConfigurationInspector&);
};

}

#endif
