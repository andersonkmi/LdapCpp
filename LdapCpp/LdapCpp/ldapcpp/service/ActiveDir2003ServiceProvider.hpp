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
#ifndef ACTIVE_DIR2003_SERVICE_PROVIDER_HPP__
#define ACTIVE_DIR2003_SERVICE_PROVIDER_HPP__

#include <ldapcpp/service/LDAPAuthServiceProvider.hpp>
#include <ldapcpp/exception/LDAPException.hpp>
#include <windows.h>
#include <winldap.h>
#include <winber.h>
#include <sstream>
#include <cctype>
#include <algorithm>

namespace ldapcpp {

class ActiveDir2003ServiceProvider : public LDAPAuthServiceProvider {
public:
	ActiveDir2003ServiceProvider();
	virtual ~ActiveDir2003ServiceProvider();

	boost::shared_ptr<LDAPUser> searchUser(const std::string& user, const std::string& baseDN) throw (LDAPException); 
	void validateUser(const boost::shared_ptr<LDAPUser>& user) throw(LDAPUserAccountDisableException, LDAPUserAccountLockoutException, LDAPUserAccountPasswordExpiredException, LDAPInvalidUserAccountException);

private:
	static const std::string SAMACCOUNT_NAME_ATTR;
	static const std::string USER_ACCOUNT_CONTROL_ATTR;
	
	ActiveDir2003ServiceProvider(const ActiveDir2003ServiceProvider&);
	ActiveDir2003ServiceProvider& operator=(const ActiveDir2003ServiceProvider&);
};

}

#endif
