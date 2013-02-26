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
#ifndef LDAP_UNWILLING_TO_PERFORM_EXCEPTION_HPP__
#define LDAP_UNWILLING_TO_PERFORM_EXCEPTION_HPP__

#include <ldapcpp/exception/LDAPException.hpp>

namespace ldapcpp {
//*****************************************************
//*** This class represents a LDAP exception
//*** Description: The server is not willing to handle 
//***              directory requests.
//*** Return code: LDAP_UNWILLING_TO_PERFORM
//*****************************************************
class LDAP_CPP_API LDAPUnwillingToPerformException : public LDAPException {
public:
	LDAPUnwillingToPerformException();
	LDAPUnwillingToPerformException(const std::string& message);
	LDAPUnwillingToPerformException(const LDAPUnwillingToPerformException& rhs);
	LDAPUnwillingToPerformException& operator=(const LDAPUnwillingToPerformException& rhs);
	virtual ~LDAPUnwillingToPerformException();

};

}

#endif
