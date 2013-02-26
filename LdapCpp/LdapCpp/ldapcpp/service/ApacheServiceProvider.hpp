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
#ifndef APACHE_SERVICE_PROVIDER_HPP__
#define APACHE_SERVICE_PROVIDER_HPP__

#ifdef LDAP_CPP_EXPORTS
#define LDAP_CPP_API __declspec(dllexport)
#else
#define LDAP_CPP_API __declspec(dllimport)
#endif

#include <ldapcpp/exception/LDAPExceptions.hpp>
#include <ldapcpp/config/LDAPConfigurationManager.hpp>
#include <ldapcpp/LDAPConnection.hpp>
#include <boost/shared_ptr.hpp>
#include <ldapcpp/service/LDAPAuthServiceProvider.hpp>
#include <sstream>
#include <windows.h>
#include <winldap.h>
#include <winber.h>
#include <string>
#include <vector>

namespace ldapcpp {

class ApacheServiceProvider : public LDAPAuthServiceProvider {
public:
	ApacheServiceProvider();
	virtual ~ApacheServiceProvider();

    boost::shared_ptr<LDAPUser> searchUser(const std::string& user, const std::string& baseDN) throw (LDAPException); 
    void validateUser(const boost::shared_ptr<LDAPUser>& user) throw(LDAPUserAccountDisableException, LDAPUserAccountLockoutException, LDAPUserAccountPasswordExpiredException, LDAPInvalidUserAccountException);
private:
	static const std::string UID_ATTR;

	ApacheServiceProvider(const ApacheServiceProvider&);
	ApacheServiceProvider& operator=(const ApacheServiceProvider&);
};

}

#endif
