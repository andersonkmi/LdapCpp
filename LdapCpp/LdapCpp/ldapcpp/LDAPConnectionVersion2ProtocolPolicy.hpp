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
#ifndef LDAP_CONNECTION_VERSION2_PROTOCOL_POLICY_HPP__
#define LDAP_CONNECTION_VERSION2_PROTOCOL_POLICY_HPP__

#pragma warning(disable: 4290)

#include <windows.h>
#include <winldap.h>
#include <string>
#include <sstream>
#include <ldapcpp/LDAPConnection.hpp>
#include <ldapcpp/exception/LDAPExceptions.hpp>

#ifdef LDAP_CPP_EXPORTS
#define LDAP_CPP_API __declspec(dllexport)
#else
#define LDAP_CPP_API __declspec(dllimport)
#endif

namespace ldapcpp {

class LDAPConnectionVersion2ProtocolPolicy {
public:
	LDAPConnectionVersion2ProtocolPolicy();
	void setProtocolVersion(LDAP* ldap);

protected:
	~LDAPConnectionVersion2ProtocolPolicy();

};

}

#endif
