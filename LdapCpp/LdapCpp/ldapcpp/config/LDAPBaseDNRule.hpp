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
#ifndef LDAP_BASE_DN_RULE_HPP__
#define LDAP_BASE_DN_RULE_HPP__

#include <ldapcpp/exception/LDAPInvalidConfigurationException.hpp>
#include <string>
#include <sstream>

#pragma warning (disable: 4290)

namespace ldapcpp {

/**
 * LDAPBaseDNRule - this class is used as a function object in the list of base DNs supplied.
 * It basically checks if each string is not empty.
 */
class LDAPBaseDNRule {
public:
	/**
	 * Default class constructor
	 */
	LDAPBaseDNRule();
	~LDAPBaseDNRule();

	/**
	 * Operator() - it takes a string as an argument.
	 * @throws LDAPInvalidConfigurationException if the base DN is an empty string.
	 */
	void operator() (const std::string& baseDN) throw (LDAPInvalidConfigurationException);
};

}

#endif
