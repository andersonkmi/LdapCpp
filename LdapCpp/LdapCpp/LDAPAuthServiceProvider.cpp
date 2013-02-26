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

#include <ldapcpp/service/LDAPAuthServiceProvider.hpp>

namespace ldapcpp {

const std::string LDAPAuthServiceProvider::OBJECT_CLASS_ATTR = "objectClass";
const std::string LDAPAuthServiceProvider::OBJECT_CLASS_ATTR_PERSON_VALUE = "person";
const std::string LDAPAuthServiceProvider::DISPLAY_NAME_ATTR = "displayName";

LDAPAuthServiceProvider::LDAPAuthServiceProvider() : isDebugMode_(false) {
}

LDAPAuthServiceProvider::~LDAPAuthServiceProvider() {
	
}

void LDAPAuthServiceProvider::connect(const std::string& server, int port, const std::string& bindUser, const std::string& bindPwd, int timeout, bool useSSL) throw (LDAPException) {
	if(isDebugMode_) {
		return;
	}

	server_ = server;
	port_ = port;
	timeout_ = timeout;
	useSSL_ = useSSL;

	if(useSSL) {
		std::ostringstream buffer;
		buffer << port;
		LDAPConnectionFactory<LDAPConnectionSSLPolicy, LDAPConnectionVersion3ProtocolPolicy, LDAPConnectionVariableTimeoutPolicy, LDAPConnectionMaker> factory(server, buffer.str());
		factory.setConnectionTimeout(timeout);
		factory.setBindTimeout(timeout);
		connection_ = factory.getConnection();
		connection_->bind(bindUser, bindPwd);
	} else {
		std::ostringstream buffer;
		buffer << port;
		LDAPConnectionFactory<LDAPConnectionNonSecurePolicy, LDAPConnectionVersion3ProtocolPolicy, LDAPConnectionVariableTimeoutPolicy, LDAPConnectionMaker> factory(server, buffer.str());
		factory.setConnectionTimeout(timeout);
		factory.setBindTimeout(timeout);
		connection_ = factory.getConnection();
		connection_->bind(bindUser, bindPwd);
	}
}

void LDAPAuthServiceProvider::bind(const std::string& user, const std::string& password) throw (LDAPException) {

	if(isDebugMode_) {
		return;
	}

	if(useSSL_) {
		
		std::ostringstream buffer;
		buffer << port_;
		LDAPConnectionFactory<LDAPConnectionSSLPolicy, LDAPConnectionVersion3ProtocolPolicy, LDAPConnectionVariableTimeoutPolicy, LDAPConnectionMaker> factory(server_, buffer.str());
		factory.setConnectionTimeout(timeout_);
		factory.setBindTimeout(timeout_);
        boost::shared_ptr<LDAPConnection> connection = factory.getConnection();
		connection->bind(user, password);
		connection->unbind();
	} else {
		
		std::ostringstream buffer;
		buffer << port_;
		LDAPConnectionFactory<LDAPConnectionNonSecurePolicy, LDAPConnectionVersion3ProtocolPolicy, LDAPConnectionVariableTimeoutPolicy, LDAPConnectionMaker> factory(server_, buffer.str());
		factory.setConnectionTimeout(timeout_);
		factory.setBindTimeout(timeout_);
        boost::shared_ptr<LDAPConnection> connection = factory.getConnection();
		connection->bind(user, password);
		connection->unbind();
	}
}
}