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
#ifndef LDAP_AUTH_SERVICE_PROVIDER_HPP__
#define LDAP_AUTH_SERVICE_PROVIDER_HPP__

#include <ldapcpp/exception/LDAPExceptions.hpp>
#include <ldapcpp/config/LDAPConfigurationManager.hpp>
#include <ldapcpp/LDAPConnection.hpp>
#include <ldapcpp/service/LDAPAuthServiceProvider.hpp>
#include <ldapcpp/data/LDAPUser.hpp>
#include <ldapcpp/exception/LDAPUserAccountDisableException.hpp>
#include <ldapcpp/exception/LDAPUserAccountLockoutException.hpp>
#include <ldapcpp/exception/LDAPUserAccountPasswordExpiredException.hpp>
#include <ldapcpp/exception/LDAPInvalidUserAccountException.hpp>
#include <ldapcpp/LDAPConnectionSSLPolicy.hpp>
#include <ldapcpp/LDAPConnectionNonSecurePolicy.hpp>
#include <ldapcpp/LDAPConnectionVersion3ProtocolPolicy.hpp>
#include <ldapcpp/LDAPConnectionVariableTimeoutPolicy.hpp>
#include <ldapcpp/LDAPConnectionFactory.hpp>
#include <ldapcpp/LDAPConnectionMaker.hpp>
#include <boost/shared_ptr.hpp>
#include <sstream>
#include <windows.h>
#include <winldap.h>
#include <winber.h>
#include <string>
#include <vector>

#pragma warning (disable: 4290)

namespace ldapcpp {

class LDAPAuthServiceProvider {
public:
	LDAPAuthServiceProvider();
	virtual ~LDAPAuthServiceProvider();

	virtual void connect(const std::string& server, int port, const std::string& bindUser, const std::string& bindPwd, int timeout, bool useSSL) throw (LDAPException);
    virtual boost::shared_ptr<LDAPUser> searchUser(const std::string& user, const std::string& baseDN) throw (LDAPException) = 0;
    virtual void validateUser(const boost::shared_ptr<LDAPUser>& user) throw(LDAPUserAccountDisableException, LDAPUserAccountLockoutException, LDAPUserAccountPasswordExpiredException, LDAPInvalidUserAccountException) = 0;
	virtual void bind(const std::string& user, const std::string& password) throw (LDAPException);

protected:
    boost::shared_ptr<LDAPConnection> connection_;
	std::string server_;
	unsigned int port_;
	unsigned int timeout_;
	bool useSSL_;
	bool isDebugMode_;

	static const std::string OBJECT_CLASS_ATTR;
	static const std::string OBJECT_CLASS_ATTR_PERSON_VALUE;
	static const std::string DISPLAY_NAME_ATTR;

	LDAPAuthServiceProvider(const LDAPAuthServiceProvider&);
	LDAPAuthServiceProvider& operator=(const LDAPAuthServiceProvider&);
};

}

#endif
