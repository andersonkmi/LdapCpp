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
#include <ldapcpp/exception/LDAPServerDownException.hpp>

namespace ldapcpp {
LDAPServerDownException::LDAPServerDownException(void) : LDAPException("") {

}

LDAPServerDownException::LDAPServerDownException(const std::string& message) : LDAPException(message) {

}

LDAPServerDownException::LDAPServerDownException(const char* message) : LDAPException(message) {

}

LDAPServerDownException::LDAPServerDownException(const LDAPServerDownException& rhs) : LDAPException(rhs) {

}

LDAPServerDownException& LDAPServerDownException::operator =(const LDAPServerDownException& rhs) {
	if(this == &rhs) {
		return *this;
	}

	LDAPException::operator=(rhs);

	return *this;
}

LDAPServerDownException::~LDAPServerDownException(void) {

}

}
