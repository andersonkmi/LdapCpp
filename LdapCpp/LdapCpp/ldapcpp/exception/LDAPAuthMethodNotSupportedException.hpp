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
#ifndef LDAP_AUTH_METHOD_NOT_SUPPORTED_EXCEPTION_HPP__
#define LDAP_AUTH_METHOD_NOT_SUPPORTED_EXCEPTION_HPP__

#include <ldapcpp/exception/LDAPException.hpp>
#include <string>

namespace ldapcpp {
//*******************************************************************
//*** This class represents a LDAP exception
//*** Description: The authentication method is not supported. 
//***              To determine the authentication methods supported 
//***              by an Active Directory server, retrieve the 
//***              SupportedSASLMechanisms property of rootDSE. For 
//***              more information, see Serverless Binding and RootDSE.
//*** Return code: LDAP_AUTH_METHOD_NOT_SUPPORTED
//*******************************************************************
class LDAP_CPP_API LDAPAuthMethodNotSupportedException : public LDAPException {
public:
	LDAPAuthMethodNotSupportedException(void);
	LDAPAuthMethodNotSupportedException(const std::string& message);
	LDAPAuthMethodNotSupportedException(const LDAPAuthMethodNotSupportedException& rhs);
	LDAPAuthMethodNotSupportedException& operator=(const LDAPAuthMethodNotSupportedException& rhs);
	virtual ~LDAPAuthMethodNotSupportedException(void);
};
}

#endif