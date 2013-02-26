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
#ifndef LDAP_SERVER_ADDR_RULE_HPP__
#define LDAP_SERVER_ADDR_RULE_HPP__

#include <string>
#include <ldapcpp/exception/LDAPInvalidConfigurationException.hpp>

#pragma warning (disable: 4290)

namespace ldapcpp {

/**
 * LDAPServerAddrRule - this class is used a function object during for the list of strings
 * containing the server addresses.
 */
class LDAPServerAddrRule {
public:
	/**
	 * Default class constructor.
	 */
	LDAPServerAddrRule();
	~LDAPServerAddrRule();

	/**
	 * Operator(). It checks a string, representing a server address and validates if it is not blank.
	 * @param server Strinng holding a server name or address.
	 * @throws LDAPInvalidConfigurationException if an empty string is found.
	 */
	void operator() (const std::string& server) throw(LDAPInvalidConfigurationException);
};

}

#endif
