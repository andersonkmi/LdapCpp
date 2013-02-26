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
#ifndef LDAP_AUTHORIZATION_PROVIDER_HPP__
#define LDAP_AUTHORIZATION_PROVIDER_HPP__

#ifdef LDAP_CPP_EXPORTS
#define LDAP_CPP_API __declspec(dllexport)
#else
#define LDAP_CPP_API __declspec(dllimport)
#endif

#include <ldapcpp/LDAPConnectionFactory.hpp>
#include <ldapcpp/config/LDAPConfigurationManager.hpp>
#include <ldapcpp/exception/LDAPExceptions.hpp>
#include <ldapcpp/service/LDAPAuthServiceProvider.hpp>
#include <ldapcpp/exception/LDAPUserAccountDisableException.hpp>
#include <ldapcpp/exception/LDAPUserAccountLockoutException.hpp>
#include <ldapcpp/exception/LDAPUserAccountPasswordExpiredException.hpp>
#include <ldapcpp/service/ApacheServiceProvider.hpp>
#include <ldapcpp/service/ActiveDir2003ServiceProvider.hpp>
#include <ldapcpp/data/LDAPUser.hpp>
#include <boost/shared_ptr.hpp>
#include <sstream>
#include <memory>

namespace ldapcpp {

class LDAP_CPP_API LDAPAuthorizationProvider {
public:
	LDAPAuthorizationProvider(const LDAPConfigurationManager& config);
	virtual ~LDAPAuthorizationProvider();

	virtual void authenticate(const std::string& user, const std::string& password) throw (LDAPException, LDAPUserAccountDisableException, LDAPUserAccountLockoutException, LDAPUserAccountPasswordExpiredException);
private:
	LDAPConfigurationManager config_;
	std::auto_ptr<LDAPAuthServiceProvider> service_;
	bool isInitialized_;
	
	LDAPAuthorizationProvider();
	LDAPAuthorizationProvider(const LDAPAuthorizationProvider&);
	LDAPAuthorizationProvider& operator=(const LDAPAuthorizationProvider&);
};

}

#endif
