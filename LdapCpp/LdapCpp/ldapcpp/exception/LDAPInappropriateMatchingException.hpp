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
#ifndef LDAP_INAPPROPRIATE_MATCHING_EXCEPTION_HPP__
#define LDAP_INAPPROPRIATE_MATCHING_EXCEPTION_HPP__

#include <ldapcpp/exception/LDAPException.hpp>
#include <string>
using namespace std;

namespace ldapcpp {

//*******************************************************************
//*** This class represents a LDAP exception
//*** Description: There was an inappropriate matching.
//*** Return code: LDAP_INAPPROPRIATE_MATCHING
//*******************************************************************
class LDAP_CPP_API LDAPInappropriateMatchingException : public LDAPException
{
public:
	LDAPInappropriateMatchingException(void);
	LDAPInappropriateMatchingException(const std::string& message);
	LDAPInappropriateMatchingException(const LDAPInappropriateMatchingException& rhs);
	LDAPInappropriateMatchingException& operator=(const LDAPInappropriateMatchingException& rhs);
	virtual ~LDAPInappropriateMatchingException(void);
};

} // end namespace declaration

#endif