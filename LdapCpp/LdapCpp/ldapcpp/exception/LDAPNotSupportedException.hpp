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
#ifndef LDAP_NOT_SUPPORTED_EXCEPTION_HPP__
#define LDAP_NOT_SUPPORTED_EXCEPTION_HPP__

#include <ldapcpp/exception/LDAPException.hpp>
#include <string>

using namespace std;

namespace ldapcpp {
//*******************************************************************
//*** This class represents a LDAP exception
//*** Description: The feature is not supported.
//*** Return code: LDAP_NOT_SUPPORTED
//*******************************************************************
class LDAP_CPP_API LDAPNotSupportedException : public LDAPException {
public:
	LDAPNotSupportedException(void);
	LDAPNotSupportedException(const string& message);
	LDAPNotSupportedException(const LDAPNotSupportedException& rhs);
	LDAPNotSupportedException& operator=(const LDAPNotSupportedException& rhs);
	virtual ~LDAPNotSupportedException(void);
};

}
#endif
