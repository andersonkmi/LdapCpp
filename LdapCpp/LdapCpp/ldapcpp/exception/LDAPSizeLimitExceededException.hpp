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
#ifndef LDAP_SIZE_LIMIT_EXCEEDED_EXCEPTION_HPP__
#define LDAP_SIZE_LIMIT_EXCEEDED_EXCEPTION_HPP__

#include <ldapcpp/exception/LDAPException.hpp>

namespace ldapcpp {
//*****************************************************
//*** This class represents a LDAP exception
//*** Description: Size limit was exceeded.
//*** Return code: LDAP_SIZELIMIT_EXCEEDED
//*****************************************************
class LDAP_CPP_API LDAPSizeLimitExceededException : public LDAPException {
public:
	LDAPSizeLimitExceededException();
	LDAPSizeLimitExceededException(const std::string& message);
	LDAPSizeLimitExceededException(const LDAPSizeLimitExceededException& rhs);
	LDAPSizeLimitExceededException& operator=(const LDAPSizeLimitExceededException& rhs);
	virtual ~LDAPSizeLimitExceededException();

};

}

#endif
