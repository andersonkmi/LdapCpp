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
#ifndef LDAP_CONNECTION_HPP__
#define LDAP_CONNECTION_HPP__

#ifdef LDAP_CPP_EXPORTS
#define LDAP_CPP_API __declspec(dllexport)
#else
#define LDAP_CPP_API __declspec(dllimport)
#endif

#include <windows.h>
#include <winldap.h>
#include <string>
#include <ldapcpp/exception/LDAPExceptions.hpp>

namespace ldapcpp {
class ActiveDir2003ServiceProvider;
class ApacheServiceProvider;
class LDAPSearch;

class LDAP_CPP_API LDAPConnection {
public:
	LDAPConnection(LDAP* ldapConn);
	~LDAPConnection(void);

	void bind(const std::string& uid, const std::string& credentials); 
	void unbind();
private:
	LDAP* ldap_;
	bool isBound_;

	friend class ActiveDir2003ServiceProvider;
	friend class ApacheServiceProvider;
	friend class LDAPSearch;
	LDAPConnection(const LDAPConnection&);
	LDAPConnection& operator=(const LDAPConnection&);
};

}
#endif