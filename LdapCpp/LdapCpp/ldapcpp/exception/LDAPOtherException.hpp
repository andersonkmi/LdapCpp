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
#ifndef LDAP_OTHER_EXCEPTION_HPP__
#define LDAP_OTHER_EXCEPTION_HPP__

#include <ldapcpp/exception/LDAPException.hpp>
#include <string>

using namespace std;

namespace ldapcpp {
//*****************************************************
//*** This class represents a LDAP exception
//*** Description: Unknown error occurred.
//*** Return code: LDAP_OTHER
//*****************************************************
class LDAP_CPP_API LDAPOtherException : public LDAPException {
public:
	LDAPOtherException(void);
	LDAPOtherException(const string& message);
	LDAPOtherException(const LDAPOtherException& rhs);
	LDAPOtherException& operator=(const LDAPOtherException& rhs);
	virtual ~LDAPOtherException(void);
};

}
#endif
