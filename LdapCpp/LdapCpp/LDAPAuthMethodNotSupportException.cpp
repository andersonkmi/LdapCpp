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
#include <ldapcpp/exception/LDAPAuthMethodNotSupportedException.hpp>

namespace ldapcpp {
LDAPAuthMethodNotSupportedException::LDAPAuthMethodNotSupportedException(void) : LDAPException("") {
}

LDAPAuthMethodNotSupportedException::LDAPAuthMethodNotSupportedException(const std::string& message) : LDAPException(message) {
}

LDAPAuthMethodNotSupportedException::LDAPAuthMethodNotSupportedException(const LDAPAuthMethodNotSupportedException& rhs) : LDAPException(rhs) {
}

LDAPAuthMethodNotSupportedException& LDAPAuthMethodNotSupportedException::operator =(const LDAPAuthMethodNotSupportedException& rhs) {
	if(this == &rhs) {
		return *this;
	}

	LDAPException::operator =(rhs);

	return *this;
}

LDAPAuthMethodNotSupportedException::~LDAPAuthMethodNotSupportedException(void)
{
}

}
