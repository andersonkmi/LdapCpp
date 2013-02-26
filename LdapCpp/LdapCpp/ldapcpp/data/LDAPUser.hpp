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
/******************************************************************************
	Modification history
	====================

	Date			Author				Description
	====			======				===========
	Fev-04-2010		andersonkmi			Initial version.
******************************************************************************/
#ifndef LDAP_USER_H__
#define LDAP_USER_H__

#ifdef LDAP_CPP_EXPORTS
#define LDAP_CPP_API __declspec(dllexport)
#else
#define LDAP_CPP_API __declspec(dllimport)
#endif

#include <string>
#include <iostream>
#include <sstream>
#include <ostream>

#pragma warning (disable: 4251)

using namespace std;

namespace ldapcpp {

/**
 * LDAPUser - this class represents a user in the LDAP server system.
 */
class LDAPUser {
public:

	//*****************************************************************************************
	//*** User account controls codes - based on Active Directory 2000 and 2003 documentation
	//*** For details refer to http://support.microsoft.com/kb/305144
	//*****************************************************************************************
	static const unsigned int SCRIPT;
	static const unsigned int ACCOUNTDISABLE; 
	static const unsigned int HOMEDIR_REQUIRED;
	static const unsigned int LOCKOUT;
	static const unsigned int PASSWD_NOTREQD;
	static const unsigned int PASSWD_CANT_CHANGE;
	static const unsigned int ENCRYPTED_TEXT_PWD_ALLOWED;
	static const unsigned int TEMP_DUPLICATE_ACCOUNT;
	static const unsigned int NORMAL_ACCOUNT;
	static const unsigned int INTERDOMAIN_TRUST_ACCOUNT;
	static const unsigned int WORKSTATION_TRUST_ACCOUNT;
	static const unsigned int SERVER_TRUST_ACCOUNT;
	static const unsigned int DONT_EXPIRE_PASSWORD;
	static const unsigned int MNS_LOGON_ACCOUNT;
	static const unsigned int SMARTCARD_REQUIRED;
	static const unsigned int TRUSTED_FOR_DELEGATION;
	static const unsigned int NOT_DELEGATED;
	static const unsigned int USE_DES_KEY_ONLY;
	static const unsigned int DONT_REQ_PREAUTH;
	static const unsigned int PASSWORD_EXPIRED;
	static const unsigned int TRUSTED_TO_AUTH_FOR_DELEGATION;

	/**
	 * Class constructor. When this constructor is used the distinguished name, display name and account control
	 * fields are initialized with default values. Distinguished and display name fields are initialized with blank
	 * values and the account control is set to a normal account.
	 * @param uid String representing the user identification.
	 */
	explicit LDAPUser(const std::string& uid);

	/**
	 * Class constructor. This constructor creates an instance using the supplied uid and dn (distinguished name)
	 * information passed in the constructor's argument. The display name and user account control fields are
	 * initialized with default values.
	 * @param uid String representing the user identification.
	 * @param dn  String representing the user's distinguished name.
	 */
	explicit LDAPUser(const std::string& uid, const std::string& dn);

	/**
	 * Class constructor. This constructor creates an instance using the supplied uid, the dn (distinguished name)
	 * and the display name information passed in the constructor's argument. The user account control field is
	 * initialized with default value.
	 * @param uid			String representing the user identification.
	 * @param dn			String representing the user's distinguished name.
	 * @param displayName	String representing the user's display name.
	 */
	explicit LDAPUser(const std::string& uid, const std::string& dn, const std::string& displayName);

	/**
	 * Class constructor. This constructor creates an instance using the supplied uid, the dn (distinguished name),
	 * the display name and the account control information passed in the constructor's argument.
	 * @param uid					String representing the user identification.
	 * @param dn					String representing the user's distinguished name.
	 * @param displayName			String representing the user's display name.
	 * @param userAccountControl	Number representing the user's account control.
	 */
	explicit LDAPUser(const std::string& uid, const std::string& dn, const std::string& displayName, unsigned int userAccountControl);

	/**
	 * Copy-constructor.
	 */
	LDAPUser(const LDAPUser& rhs);

	/**
	 * Operator assignment.
	 */
	LDAPUser& operator=(const LDAPUser& rhs);
	virtual ~LDAPUser(void);

	/**
	 * Sets the display name information of the user.
	 * @param displayName String containing the new display name.
	 */
	virtual void setDisplayName(const std::string& displayName);

	/**
	 * Sets the distinguished name information of the user.
	 * @param dn String containing the new distinguished name.
	 */
	virtual void setDN(const std::string& dn);

	/**
	 * Sets the user's account control information.
	 * @param userAccountControl Number representing one of the possible account status information.
	 */
	virtual void setUserAccountControl(unsigned int userAccountControl);

	/**
	 * Returns the user identification.
	 * @return String containing the user identification.
	 */
	std::string getUid() const;

	/**
	 * Returns the user's display name.
	 * @return String containing the user's display name information.
	 */
	std::string getDisplayName() const;

	/**
	 * Returns the user's distinghished name.
	 * @return String containing the user's distinguished name information.
	 */
	std::string getDN() const;

	/**
	 * Returns the user's account control number.
	 * @return Integer number representing the user's account control status.
	 */
	unsigned int getUserAccountControl() const;

	/**
	 * Returns the user identification.
	 * @return String containing the user identification.
	 */
	std::string getUid();
	
	/**
	 * Returns the user's display name.
	 * @return String containing the user's display name information.
	 */
	std::string getDisplayName();

	/**
	 * Returns the user's distinghished name.
	 * @return String containing the user's distinguished name information.
	 */	
	std::string getDN();

	/**
	 * Returns the user's account control number.
	 * @return Integer number representing the user's account control status.
	 */
	unsigned int getUserAccountControl();

	friend LDAP_CPP_API std::ostream& operator<<(std::ostream& os, const LDAPUser& user);
	friend LDAP_CPP_API bool operator==(const LDAPUser& lhs, const LDAPUser& rhs);
private:
	// Disables default constructor
	LDAPUser(void);

	std::string uid_;
	std::string dn_;
	std::string displayName_;
	unsigned int userAccountControl_;
};

}

#endif
