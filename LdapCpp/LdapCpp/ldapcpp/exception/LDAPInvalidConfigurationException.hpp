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
#ifndef LDAP_INVALID_CONFIGURATION_EXCEPTION_HPP__
#define LDAP_INVALID_CONFIGURATION_EXCEPTION_HPP__

#ifdef LDAP_CPP_EXPORTS
#define LDAP_CPP_API __declspec(dllexport)
#else
#define LDAP_CPP_API __declspec(dllimport)
#endif

#include <stdexcept>

#pragma warning (disable: 4275)

namespace ldapcpp {

/**
 * LDAPInvalidConfigurationException - this is an exception class used when
 * the configuration is missing mandatory information.
 */
class LDAP_CPP_API LDAPInvalidConfigurationException : public std::runtime_error {
public:
	/**
	 * Default class constructor
	 */
	LDAPInvalidConfigurationException(void) throw();
	
	/**
	 * Alternative class constructor that accepts a string containing the exception message.
	 * @param message String containing a message about the exception.
	 */
	LDAPInvalidConfigurationException(const std::string& message);
	
	/**
	 * Copy constructor.
	 */
	LDAPInvalidConfigurationException(const LDAPInvalidConfigurationException& rhs);

	/**
	 * Operator assignment
	 */
	LDAPInvalidConfigurationException& operator=(const LDAPInvalidConfigurationException& rhs);
	virtual ~LDAPInvalidConfigurationException(void);
};

}

#endif
