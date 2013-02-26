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
#include <ldapcpp/data/LDAPUser.hpp>

namespace ldapcpp {

const unsigned int LDAPUser::SCRIPT = 0x0001;
const unsigned int LDAPUser::ACCOUNTDISABLE = 0x0002; 
const unsigned int LDAPUser::HOMEDIR_REQUIRED = 0x0008;
const unsigned int LDAPUser::LOCKOUT = 0x0010;
const unsigned int LDAPUser::PASSWD_NOTREQD = 0x0020;
const unsigned int LDAPUser::PASSWD_CANT_CHANGE = 0x0040;
const unsigned int LDAPUser::ENCRYPTED_TEXT_PWD_ALLOWED = 0x0080;
const unsigned int LDAPUser::TEMP_DUPLICATE_ACCOUNT = 0x0100;
const unsigned int LDAPUser::NORMAL_ACCOUNT = 0x0200;
const unsigned int LDAPUser::INTERDOMAIN_TRUST_ACCOUNT = 0x0800;
const unsigned int LDAPUser::WORKSTATION_TRUST_ACCOUNT = 0x1000;
const unsigned int LDAPUser::SERVER_TRUST_ACCOUNT = 0x2000;
const unsigned int LDAPUser::DONT_EXPIRE_PASSWORD = 0x10000;
const unsigned int LDAPUser::MNS_LOGON_ACCOUNT = 0x20000;
const unsigned int LDAPUser::SMARTCARD_REQUIRED = 0x40000;
const unsigned int LDAPUser::TRUSTED_FOR_DELEGATION = 0x80000;
const unsigned int LDAPUser::NOT_DELEGATED = 0x100000;
const unsigned int LDAPUser::USE_DES_KEY_ONLY = 0x200000;
const unsigned int LDAPUser::DONT_REQ_PREAUTH = 0x400000;
const unsigned int LDAPUser::PASSWORD_EXPIRED = 0x800000;
const unsigned int LDAPUser::TRUSTED_TO_AUTH_FOR_DELEGATION = 0x1000000;

LDAPUser::LDAPUser(void) {
}


LDAPUser::LDAPUser(const std::string &uid) : uid_(uid), dn_(" "), displayName_(" "), userAccountControl_(LDAPUser::NORMAL_ACCOUNT) {

}

LDAPUser::LDAPUser(const std::string &uid, const std::string &dn) : uid_(uid), dn_(dn), displayName_(""), userAccountControl_(LDAPUser::NORMAL_ACCOUNT) {

}

LDAPUser::LDAPUser(const std::string &uid, const std::string &dn, const std::string &displayName) : uid_(uid), dn_(dn), displayName_(displayName), userAccountControl_(LDAPUser::NORMAL_ACCOUNT) {

}

LDAPUser::LDAPUser(const std::string &uid, const std::string &dn, const std::string &displayName, unsigned int userAccountControl) : uid_(uid), dn_(dn), displayName_(displayName), userAccountControl_(userAccountControl) {

}

LDAPUser::LDAPUser(const LDAPUser& rhs) : uid_(rhs.uid_), dn_(rhs.dn_), displayName_(rhs.displayName_), userAccountControl_(rhs.userAccountControl_) {

}

LDAPUser& LDAPUser::operator=(const LDAPUser& rhs) {
	if(&rhs == this) {
		return *this;
	}

	uid_ = rhs.uid_;
	dn_ = rhs.dn_;
	displayName_ = rhs.displayName_;
	userAccountControl_ = rhs.userAccountControl_;

	return *this;
}

LDAPUser::~LDAPUser(void) {
}

void LDAPUser::setDisplayName(const std::string &displayName) {
	displayName_ = displayName;
}

void LDAPUser::setDN(const std::string &dn) {
	dn_ = dn;
}

void LDAPUser::setUserAccountControl(unsigned int userAccountControl) {
	userAccountControl_ = userAccountControl;
}

std::string LDAPUser::getUid() const {
	return uid_;
}

std::string LDAPUser::getDisplayName() const {
	return displayName_;
}

std::string LDAPUser::getDN() const {
	return dn_;
}

unsigned int LDAPUser::getUserAccountControl() const {
	return userAccountControl_;
}


std::string LDAPUser::getUid() {
	return uid_;
}

std::string LDAPUser::getDisplayName() {
	return displayName_;
}

std::string LDAPUser::getDN() {
	return dn_;
}

unsigned int LDAPUser::getUserAccountControl() {
	return userAccountControl_;
}

std::ostream& operator<<(std::ostream& os, const LDAPUser& rhs) {
	os << "LDAPUser[uid = '" << rhs.uid_ << "'; displayName = '" << rhs.displayName_ << "'; DN = '" << rhs.dn_ << "'; userAccountControl = '" << rhs.userAccountControl_ << "'";
	return os;
}

bool operator==(const LDAPUser& lhs, const LDAPUser& rhs) {
	return lhs.uid_ == rhs.uid_;
}

}