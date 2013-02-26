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

#include <ldapcpp/exception/LDAPUserAccountDisableException.hpp>

namespace ldapcpp {

LDAPUserAccountDisableException::LDAPUserAccountDisableException() throw() : std::runtime_error("LDAPUserAccountDisableException raised") {

}

LDAPUserAccountDisableException::LDAPUserAccountDisableException(const std::string& message) throw() : std::runtime_error(message) {
}


LDAPUserAccountDisableException::~LDAPUserAccountDisableException() {

}

LDAPUserAccountDisableException::LDAPUserAccountDisableException(const LDAPUserAccountDisableException& rhs) throw() : std::runtime_error(rhs) {
}

LDAPUserAccountDisableException& LDAPUserAccountDisableException::operator=(const LDAPUserAccountDisableException& rhs) throw() {
	if(this == &rhs) {
		return *this;
	}

	exception::operator =(rhs);

	return *this;
}

}
