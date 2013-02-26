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
#include <ldapcpp/service/LDAPAuthorizationProvider.hpp>

namespace ldapcpp {

LDAPAuthorizationProvider::LDAPAuthorizationProvider(const LDAPConfigurationManager& config) : config_(config), service_(NULL), isInitialized_(false) {

	
	if(config.getServerVendor().compare(LDAPConfigurationManager::APACHE_DIR_SERVER) == 0) {
		std::auto_ptr<LDAPAuthServiceProvider> temp(new ApacheServiceProvider);
		service_ = temp;
		isInitialized_ = true;

		
	} else if(config.getServerVendor().compare(LDAPConfigurationManager::MS_ACTIVE_DIRECTORY_2003) == 0 ||
		      config.getServerVendor().compare(LDAPConfigurationManager::MS_ACTIVE_DIRECTORY_2000) == 0) {
		std::auto_ptr<LDAPAuthServiceProvider> temp(new ActiveDir2003ServiceProvider);
		service_ = temp;
		isInitialized_ = true;
	}
}

LDAPAuthorizationProvider::~LDAPAuthorizationProvider()
{

}

void LDAPAuthorizationProvider::authenticate(const std::string& user, const std::string& password) throw (LDAPException, LDAPUserAccountDisableException, LDAPUserAccountLockoutException, LDAPUserAccountPasswordExpiredException) {
	if(!isInitialized_) {
		throw LDAPException("LDAP authorization provider is not properly initialized.");
	}

	

	std::ostringstream buffer;
	std::vector<std::string> servers = config_.getServers();
	int count = servers.size();

	bool useSSL = config_.isSSLEnabled();
	unsigned int port = config_.getPort();
	unsigned int timeout = config_.getTimeout();
	std::string bindUser = config_.getBindUser();
	std::string bindUserPwd = config_.getBindPwd();

	unsigned int errorCount = 0;
	bool isConnected = false;

	for(int i = 0; i < count && !isConnected; i++) {
		std::string server = servers[i];

		

		try {
			service_->connect(server, port, bindUser, bindUserPwd, timeout, useSSL);
			isConnected = true;
		} catch (const LDAPServerDownException& exception) {
			buffer << "Connection error: " << exception.what() << std::endl;
			if(++errorCount == count) {
				throw LDAPServerDownException(buffer.str());
			}
		}
	}

	std::vector<std::string> baseDNs = config_.getBaseDNs();
	count = baseDNs.size();
	errorCount = 0;

	bool isFound = false;
	std::string userDN;
	boost::shared_ptr<LDAPUser> ldapUser;

	for(int j = 0; j < count && !isFound; j++) {
		std::string baseDN = baseDNs[j];

		try {
			ldapUser = service_->searchUser(user, baseDN);
			isFound = true;
		} catch (const LDAPNoSuchObjectException& exception) {
			buffer << "Search error: " << exception.what();
			if(++errorCount == count) {
				throw LDAPNoSuchObjectException(buffer.str());
			}
		} catch (const LDAPInvalidCredentialsException& exception) {
			buffer << "Search error: " << exception.what();
			if(++errorCount == count) {
				throw LDAPInvalidCredentialsException(buffer.str());
			}
		} catch (const LDAPOperationsErrorException& exception) {
			buffer << "Search error: " << exception.what();
			if(++errorCount == count) {
				throw LDAPOperationsErrorException(buffer.str());
			}
		} catch (const LDAPException& exception) {
			buffer << "Search error: " << exception.what();
			if(++errorCount == count) {
				throw LDAPException(buffer.str());
			}
		}
	}
	service_->validateUser(ldapUser);
	service_->bind(ldapUser->getDN(), password);

}

}
