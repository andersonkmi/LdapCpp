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

#include <ldapcpp/service/ApacheServiceProvider.hpp>
namespace ldapcpp {

const std::string ApacheServiceProvider::UID_ATTR = "uid";

ApacheServiceProvider::ApacheServiceProvider()
{

}

ApacheServiceProvider::~ApacheServiceProvider()
{

}

boost::shared_ptr<LDAPUser> ApacheServiceProvider::searchUser(const std::string& user, const std::string& baseDN) throw (LDAPException) {
	std::ostringstream buffer;
	buffer << "(&(" << UID_ATTR << "=" << user << ")(" << LDAPAuthServiceProvider::OBJECT_CLASS_ATTR << "=" << LDAPAuthServiceProvider::OBJECT_CLASS_ATTR_PERSON_VALUE << "))";
	std::string searchFilter = buffer.str();
	PCHAR filter = const_cast<char*>(searchFilter.c_str());

	PCHAR resultAttributes[2];
	resultAttributes[0] = const_cast<char*>(LDAPAuthServiceProvider::DISPLAY_NAME_ATTR.c_str());
    resultAttributes[1] = NULL;

	PCHAR baseDNConstChar = const_cast<char*>(baseDN.c_str());
	LDAPMessage* searchResults;
		
    int returnCode = ldap_search_s(
                    connection_->ldap_,    // Session handle
                    baseDNConstChar,              // DN to start search
                    LDAP_SCOPE_SUBTREE, // Scope
                    filter,          // Filter
                    resultAttributes,      // Retrieve list of attributes
	                0,                  // Get both attributes and values
                    &searchResults);    // [out] Search results

	if(returnCode != LDAP_SUCCESS) {
		std::ostringstream buffer;
		buffer << "LDAP search failed: ";
		ULONG errorCode = LdapGetLastError();
		ULONG win32ErrorCode = LdapMapErrorToWin32(errorCode);

		LPVOID lpMsgBuf;
		FormatMessage( 
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			win32ErrorCode,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPTSTR) &lpMsgBuf,
			0,
			NULL 
		);
		std::string win32Message((LPCTSTR)lpMsgBuf);
		LocalFree( lpMsgBuf );

		buffer << win32Message;

		switch(returnCode) {
			case LDAP_ADMIN_LIMIT_EXCEEDED:
				ldap_msgfree(searchResults);
				throw LDAPAdminLimitExceededException(buffer.str());
			
			case LDAP_AFFECTS_MULTIPLE_DSAS:
				ldap_msgfree(searchResults);
				throw LDAPAffectsMultipleDsasException(buffer.str());
			
			case LDAP_ALIAS_DEREF_PROBLEM:
				ldap_msgfree(searchResults);
				throw LDAPAliasDerefProblemException(buffer.str());
			
			case LDAP_ALIAS_PROBLEM:
				ldap_msgfree(searchResults);
				throw LDAPAliasProblemException(buffer.str());
			
			case LDAP_ALREADY_EXISTS:
				ldap_msgfree(searchResults);
				throw LDAPAlreadyExistsException(buffer.str());
			
			case LDAP_ATTRIBUTE_OR_VALUE_EXISTS:
				ldap_msgfree(searchResults);
				throw LDAPAttributeOrValueExistsException(buffer.str());
			
			case LDAP_AUTH_METHOD_NOT_SUPPORTED:
				ldap_msgfree(searchResults);
				throw LDAPAuthMethodNotSupportedException(buffer.str());
			
			case LDAP_AUTH_UNKNOWN:
				ldap_msgfree(searchResults);
				throw LDAPAuthUnknownException(buffer.str());
			
			case LDAP_BUSY:
				ldap_msgfree(searchResults);
				throw LDAPBusyException(buffer.str());
			
			case LDAP_CLIENT_LOOP:
				ldap_msgfree(searchResults);
				throw LDAPClientLoopException(buffer.str());
			
			case LDAP_CONFIDENTIALITY_REQUIRED:
				ldap_msgfree(searchResults);
				throw LDAPConfidentialityRequiredException(buffer.str());
			
			case LDAP_CONNECT_ERROR:
				ldap_msgfree(searchResults);
				throw LDAPConnectErrorException(buffer.str());
			
			case LDAP_CONSTRAINT_VIOLATION:
				ldap_msgfree(searchResults);
				throw LDAPConstraintViolationException(buffer.str());

			case LDAP_CONTROL_NOT_FOUND:
				ldap_msgfree(searchResults);
				throw LDAPControlNotFoundException(buffer.str());

			case LDAP_DECODING_ERROR:
				ldap_msgfree(searchResults);
				throw LDAPDecodingErrorException(buffer.str());

			case LDAP_ENCODING_ERROR:
				ldap_msgfree(searchResults);
				throw LDAPEncodingErrorException(buffer.str());

			case LDAP_FILTER_ERROR:
				ldap_msgfree(searchResults);
				throw LDAPFilterErrorException(buffer.str());

			case LDAP_INAPPROPRIATE_AUTH:
				ldap_msgfree(searchResults);
				throw LDAPInappropriateAuthException(buffer.str());

			case LDAP_INAPPROPRIATE_MATCHING:
				ldap_msgfree(searchResults);
				throw LDAPInappropriateMatchingException(buffer.str());

			case LDAP_INSUFFICIENT_RIGHTS:
				ldap_msgfree(searchResults);
				throw LDAPInsufficientRightsException(buffer.str());

			case LDAP_INVALID_CREDENTIALS:
				ldap_msgfree(searchResults);
				throw LDAPInvalidCredentialsException(buffer.str());

			case LDAP_INVALID_DN_SYNTAX:
				ldap_msgfree(searchResults);
				throw LDAPInvalidDNSyntaxException(buffer.str());

			case LDAP_INVALID_SYNTAX:
				ldap_msgfree(searchResults);
				throw LDAPInvalidSyntaxException(buffer.str());

			case LDAP_LOCAL_ERROR:
				ldap_msgfree(searchResults);
				throw LDAPLocalErrorException(buffer.str());

			case LDAP_NAMING_VIOLATION:
				ldap_msgfree(searchResults);
				throw LDAPNamingViolationException(buffer.str());

			case LDAP_NO_MEMORY:
				ldap_msgfree(searchResults);
				throw LDAPNoMemoryException(buffer.str());

			case LDAP_NO_OBJECT_CLASS_MODS:
				ldap_msgfree(searchResults);
				throw LDAPNoObjectClassModsException(buffer.str());

			case LDAP_NO_RESULTS_RETURNED:
				ldap_msgfree(searchResults);
				throw LDAPNoResultsReturnedException(buffer.str());

			case LDAP_NO_SUCH_ATTRIBUTE:
				ldap_msgfree(searchResults);
				throw LDAPNoSuchAttributeException(buffer.str());

			case LDAP_NO_SUCH_OBJECT:
				ldap_msgfree(searchResults);
				throw LDAPNoSuchObjectException(buffer.str());

			case LDAP_NOT_ALLOWED_ON_NONLEAF:
				ldap_msgfree(searchResults);
				throw LDAPOpNotAllowedOnNonleafException(buffer.str());

			case LDAP_NOT_ALLOWED_ON_RDN:
				ldap_msgfree(searchResults);
				throw LDAPOpNotAllowedOnRDNException(buffer.str());

			case LDAP_NOT_SUPPORTED:
				ldap_msgfree(searchResults);
				throw LDAPNotSupportedException(buffer.str());

			case LDAP_OBJECT_CLASS_VIOLATION:
				ldap_msgfree(searchResults);
				throw LDAPObjectClassViolationException(buffer.str());

			case LDAP_OPERATIONS_ERROR:
				ldap_msgfree(searchResults);
				throw LDAPOperationsErrorException(buffer.str());

			case LDAP_OTHER:
				ldap_msgfree(searchResults);
				throw LDAPOtherException(buffer.str());

			case LDAP_PARAM_ERROR:
				ldap_msgfree(searchResults);
				throw LDAPParamErrorException(buffer.str());

			case LDAP_PROTOCOL_ERROR:
				ldap_msgfree(searchResults);
				throw LDAPProtocolErrorException(buffer.str());

			case LDAP_REFERRAL_LIMIT_EXCEEDED:
				ldap_msgfree(searchResults);
				throw LDAPReferralLimitExceededException(buffer.str());

			case LDAP_RESULTS_TOO_LARGE:
				ldap_msgfree(searchResults);
				throw LDAPResultsTooLargeException(buffer.str());

			case LDAP_SERVER_DOWN:
				ldap_msgfree(searchResults);
				throw LDAPServerDownException(buffer.str());

			case LDAP_SIZELIMIT_EXCEEDED:
				ldap_msgfree(searchResults);
				throw LDAPSizeLimitExceededException(buffer.str());

			case LDAP_STRONG_AUTH_REQUIRED:
				ldap_msgfree(searchResults);
				throw LDAPStrongAuthRequiredException(buffer.str());

			case LDAP_TIMELIMIT_EXCEEDED:
				ldap_msgfree(searchResults);
				throw LDAPTimeLimitExceededException(buffer.str());

			case LDAP_TIMEOUT:
				ldap_msgfree(searchResults);
				throw LDAPTimeoutException(buffer.str());

			case LDAP_UNAVAILABLE:
				ldap_msgfree(searchResults);
				throw LDAPUnavailableException(buffer.str());

			case LDAP_UNAVAILABLE_CRIT_EXTENSION:
				ldap_msgfree(searchResults);
				throw LDAPUnavailableCritExtensionException(buffer.str());

			case LDAP_UNDEFINED_TYPE:
				ldap_msgfree(searchResults);
				throw LDAPUndefinedTypeException(buffer.str());

			case LDAP_UNWILLING_TO_PERFORM:
				ldap_msgfree(searchResults);
				throw LDAPUnwillingToPerformException(buffer.str());

			case LDAP_USER_CANCELLED:
				ldap_msgfree(searchResults);
				throw LDAPUserCancelledException(buffer.str());

			case LDAP_VIRTUAL_LIST_VIEW_ERROR:
				ldap_msgfree(searchResults);
				throw LDAPVirtualListViewErrorException(buffer.str());
		}
	}

	LDAPMessage* pEntry = NULL;    
    pEntry = ldap_first_entry(connection_->ldap_, searchResults);
    
	std::string userDN("");
    if(pEntry == NULL) {
		ldap_msgfree(searchResults);
		throw LDAPInvalidCredentialsException("User not found");
    } else {
		PCHAR dn = ldap_get_dn(connection_->ldap_, pEntry);
		std::string dn_str(dn);
		userDN = dn_str;
	}
	
    PCHAR pEntryDN = NULL;
    BerElement* pBer = NULL;
    PCHAR pAttribute = NULL;
    PCHAR* ppValue = NULL;
    ULONG iValue = 0;
                    
    // Get the firt attribute name.
    pAttribute = ldap_first_attribute(
                  connection_->ldap_,   // Session handle
                  pEntry,            // Current entry
                  &pBer);            // [out] Current BerElement

	std::string displayName;
	std::ostringstream bufferValue;
    while(pAttribute != NULL) {        
		buffer << pAttribute;
        ppValue = ldap_get_values(
                      connection_->ldap_,  // Session Handle
                      pEntry,           // Current entry
                      pAttribute);      // Current attribute
		
        if(ppValue != NULL) {
            iValue = ldap_count_values(ppValue);
            if(iValue != NULL)
            {
				bufferValue << *ppValue;
				displayName = bufferValue.str();
            }
        } 

        if(ppValue != NULL) {  
            ldap_value_free(ppValue);
		}

        ppValue = NULL;
        ldap_memfree(pAttribute);
        
        // Get next attribute name.
        pAttribute = ldap_next_attribute(
                        connection_->ldap_,   // Session Handle
                        pEntry,            // Current entry
                        pBer);             // Current BerElement
    }
    
    if( pBer != NULL ) {
        ber_free(pBer, 0);
	}
    pBer = NULL;

	
	ldap_msgfree(searchResults);
	boost::shared_ptr<LDAPUser> ldapUser(new LDAPUser(user, userDN, displayName));

	return ldapUser;
}

void ApacheServiceProvider::validateUser(const boost::shared_ptr<LDAPUser>& user) throw (LDAPUserAccountDisableException, LDAPUserAccountLockoutException, LDAPUserAccountPasswordExpiredException, LDAPInvalidUserAccountException) {


	unsigned int accountControl = user->getUserAccountControl();
	if((accountControl & LDAPUser::ACCOUNTDISABLE) == LDAPUser::ACCOUNTDISABLE) {
		std::ostringstream message;
		message << "Account '" << user->getUid() << "' is disabled.";
		throw LDAPUserAccountDisableException(message.str());
	} else if((accountControl & LDAPUser::PASSWORD_EXPIRED) == LDAPUser::PASSWORD_EXPIRED) {
		std::ostringstream message;
		message << "Account '" << user->getUid() << "' is password expired.";
		throw LDAPUserAccountPasswordExpiredException(message.str());
	} else if((accountControl & LDAPUser::LOCKOUT) == LDAPUser::LOCKOUT) {
		std::ostringstream message;
		message << "Account '" << user->getUid() << "' is locked out.";
		throw LDAPUserAccountLockoutException(message.str());
	} else if((accountControl & LDAPUser::NORMAL_ACCOUNT) != LDAPUser::NORMAL_ACCOUNT) { 
		std::ostringstream message;
		message << "Account '" << user->getUid() << "' is not a normal account.";
		throw LDAPInvalidUserAccountException(message.str());
	}

}

}
