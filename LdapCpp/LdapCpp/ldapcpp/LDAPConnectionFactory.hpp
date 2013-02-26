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
#ifndef LDAP_CONN_FACTORY_HPP__
#define LDAP_CONN_FACTORY_HPP__

#ifdef LDAP_CPP_EXPORTS
#define LDAP_CPP_API __declspec(dllexport)
#else
#define LDAP_CPP_API __declspec(dllimport)
#endif

#pragma warning(disable: 4290 4786)

#include <windows.h>
#include <winldap.h>
#include <string>
#include <sstream>
#include <boost/shared_ptr.hpp>
#include <ldapcpp/LDAPConnection.hpp>
#include <ldapcpp/exception/LDAPExceptions.hpp>

using namespace std;

namespace ldapcpp {

template<class ConnectionSecurityPolicy, class ConnectionProtocolVersionPolicy, class ConnectionTimeoutPolicy, class ConnectionMaker>
class LDAPConnectionFactory : public ConnectionSecurityPolicy, public ConnectionProtocolVersionPolicy, public ConnectionTimeoutPolicy, public ConnectionMaker {
public:
	LDAPConnectionFactory(const std::string& hostname, const std::string& port) : server_(hostname), port_(port) {

	}

	~LDAPConnectionFactory() {
	}

	boost::shared_ptr<LDAPConnection> getConnection() {
		

		LDAP* ldap = 0;
		ldap = ConnectionSecurityPolicy::initialize(server_, port_);
		ConnectionProtocolVersionPolicy::setProtocolVersion(ldap);
		ConnectionTimeoutPolicy::setTimeout(ldap);
		ConnectionMaker::connect(ldap);
		boost::shared_ptr<LDAPConnection> conn(new LDAPConnection(ldap));
		return conn;	
	}
private:
	std::string server_;
	std::string port_;

	LDAPConnectionFactory();
};

}
#endif
