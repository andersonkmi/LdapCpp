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
#include <ldapcpp/config/LDAPConfigurationManager.hpp>

namespace ldapcpp {

const std::string LDAPConfigurationManager::APACHE_DIR_SERVER = "ApacheDS";
const std::string LDAPConfigurationManager::MS_ACTIVE_DIRECTORY_2000 = "AD2000";
const std::string LDAPConfigurationManager::MS_ACTIVE_DIRECTORY_2003 = "AD2003";

LDAPConfigurationManager::LDAPConfigurationManager() : bindUser_(""), bindPwd_(""), enableSSL_(false), port_(0), serverVendor_(""), timeout_(0)
{

}


LDAPConfigurationManager::~LDAPConfigurationManager()
{

}

LDAPConfigurationManager::LDAPConfigurationManager(const LDAPConfigurationManager& rhs) : bindUser_(rhs.bindUser_), 
	                                                                                      bindPwd_(rhs.bindPwd_), 
																						  enableSSL_(rhs.enableSSL_), 
																						  port_(rhs.port_), 
																						  serverVendor_(rhs.serverVendor_), 
																						  timeout_(rhs.timeout_), 
																						  servers_(rhs.servers_), 
																						  baseDNs_(rhs.baseDNs_), 
																						  groupBaseDNs_(rhs.groupBaseDNs_) {

}

LDAPConfigurationManager& LDAPConfigurationManager::operator= (const LDAPConfigurationManager& rhs) {
	if(this == &rhs) {
		return *this;
	}

	baseDNs_ = rhs.baseDNs_;
	groupBaseDNs_ = rhs.groupBaseDNs_;
	bindPwd_ = rhs.bindPwd_;
	bindUser_ = rhs.bindUser_;
	enableSSL_ = rhs.enableSSL_;
	port_ = rhs.port_;
	servers_ = rhs.servers_;
	serverVendor_ = rhs.serverVendor_;
	timeout_ = rhs.timeout_;

	return *this;
}

void LDAPConfigurationManager::setServerVendor(const std::string& vendor) {
	serverVendor_ = vendor;
}

void LDAPConfigurationManager::addServer(const std::string& server) {
	servers_.push_back(server);
}


void LDAPConfigurationManager::setPort(unsigned int port) {
	port_ = port;
}

void LDAPConfigurationManager::addBaseDN(const std::string& baseDN) {
	baseDNs_.push_back(baseDN);
}


void LDAPConfigurationManager::setBindUser(const std::string& bind) {
	bindUser_ = bind;
}


void LDAPConfigurationManager::setBindPwd(const std::string& pwd) {
	bindPwd_ = pwd;
}


void LDAPConfigurationManager::setTimeout(unsigned int timeout) {
	timeout_ = timeout;
}

void LDAPConfigurationManager::setEnableSSL(bool flag) {
	enableSSL_ = flag;
}

std::string LDAPConfigurationManager::getServerVendor() const {
	return serverVendor_;
}

std::string LDAPConfigurationManager::getServerVendor() {
	return serverVendor_;
}

unsigned int LDAPConfigurationManager::getPort() const {
	return port_;
}

unsigned int LDAPConfigurationManager::getPort() {
	return port_;
}

std::string LDAPConfigurationManager::getBindUser() const {
	return bindUser_;
}

std::string LDAPConfigurationManager::getBindUser() {
	return bindUser_;
}

std::string LDAPConfigurationManager::getBindPwd() const {
	return bindPwd_;
}

std::string LDAPConfigurationManager::getBindPwd() {
	return bindPwd_;
}

unsigned int LDAPConfigurationManager::getTimeout() const {
	return timeout_;
}

unsigned int LDAPConfigurationManager::getTimeout() {
	return timeout_;
}

bool LDAPConfigurationManager::isSSLEnabled() const {
	return enableSSL_;
}

bool LDAPConfigurationManager::isSSLEnabled() {
	return enableSSL_;
}

std::vector<std::string> LDAPConfigurationManager::getServers() const {
	return servers_;
}

std::vector<std::string> LDAPConfigurationManager::getServers() {
	return servers_;
}

std::vector<std::string> LDAPConfigurationManager::getBaseDNs() const {
	return baseDNs_;
}

std::vector<std::string> LDAPConfigurationManager::getBaseDNs() {
	return baseDNs_;
}

void LDAPConfigurationManager::addGroupBaseDN(const std::string& groupBaseDN) {
	groupBaseDNs_.push_back(groupBaseDN);
}

std::vector<std::string> LDAPConfigurationManager::getGroupBaseDNs() const {
	return groupBaseDNs_;
}

std::vector<std::string> LDAPConfigurationManager::getGroupBaseDNs() {
	return groupBaseDNs_;
}
}
