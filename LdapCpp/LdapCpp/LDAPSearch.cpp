#include <ldapcpp/LDAPSearch.hpp>
#include <windows.h>
#include <winldap.h>
#include <winber.h>

namespace ldapcpp {

LDAPSearch::LDAPSearch(void)
{
}

LDAPSearch::LDAPSearch(const std::string& base, const boost::shared_ptr<LDAPConnection>& connection) : baseDN_(base), connection_(connection) {
}

LDAPSearch::~LDAPSearch(void)
{
}


boost::shared_ptr<LDAPUser> LDAPSearch::search(const std::string& userName) {
	std::string searchFilter = getSearchFilter(userName);
	std::vector<std::string> attrs = getSearchAttrs();
	PCHAR searchDN = const_cast<char*>(baseDN_.c_str());
    LDAPMessage* searchResults;
    PCHAR filter = const_cast<char*>(searchFilter.c_str());

	int size = attrs.size();
	PCHAR* attributes = new PCHAR[size + 1];

	int index = 0;
	while(index < size) {
		std::string attr = attrs[index];
		attributes[index] = const_cast<char*>(attr.c_str());
		++index;
	}
	attributes[size] = NULL;

	PCHAR baseDn = const_cast<char*>(baseDN_.c_str());
		
    int returnCode = ldap_search_s(
                    connection_->ldap_,    // Session handle
                    baseDn,              // DN to start search
                    LDAP_SCOPE_SUBTREE, // Scope
                    filter,          // Filter
                    attributes,      // Retrieve list of attributes
	                0,                  // Get both attributes and values
                    &searchResults);    // [out] Search results
	delete[] attributes;

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
				throw LDAPAdminLimitExceededException(buffer.str());
			
			case LDAP_AFFECTS_MULTIPLE_DSAS:
				throw LDAPAffectsMultipleDsasException(buffer.str());
			
			case LDAP_ALIAS_DEREF_PROBLEM:
				throw LDAPAliasDerefProblemException(buffer.str());
			
			case LDAP_ALIAS_PROBLEM:
				throw LDAPAliasProblemException(buffer.str());
			
			case LDAP_ALREADY_EXISTS:
				throw LDAPAlreadyExistsException(buffer.str());
			
			case LDAP_ATTRIBUTE_OR_VALUE_EXISTS:
				throw LDAPAttributeOrValueExistsException(buffer.str());
			
			case LDAP_AUTH_METHOD_NOT_SUPPORTED:
				throw LDAPAuthMethodNotSupportedException(buffer.str());
			
			case LDAP_AUTH_UNKNOWN:
				throw LDAPAuthUnknownException(buffer.str());
			
			case LDAP_BUSY:
				throw LDAPBusyException(buffer.str());
			
			case LDAP_CLIENT_LOOP:
				throw LDAPClientLoopException(buffer.str());
			
			case LDAP_CONFIDENTIALITY_REQUIRED:
				throw LDAPConfidentialityRequiredException(buffer.str());
			
			case LDAP_CONNECT_ERROR:
				throw LDAPConnectErrorException(buffer.str());
			
			case LDAP_CONSTRAINT_VIOLATION:
				throw LDAPConstraintViolationException(buffer.str());

			case LDAP_CONTROL_NOT_FOUND:
				throw LDAPControlNotFoundException(buffer.str());

			case LDAP_DECODING_ERROR:
				throw LDAPDecodingErrorException(buffer.str());

			case LDAP_ENCODING_ERROR:
				throw LDAPEncodingErrorException(buffer.str());

			case LDAP_FILTER_ERROR:
				throw LDAPFilterErrorException(buffer.str());

			case LDAP_INAPPROPRIATE_AUTH:
				throw LDAPInappropriateAuthException(buffer.str());

			case LDAP_INAPPROPRIATE_MATCHING:
				throw LDAPInappropriateMatchingException(buffer.str());

			case LDAP_INSUFFICIENT_RIGHTS:
				throw LDAPInsufficientRightsException(buffer.str());

			case LDAP_INVALID_CREDENTIALS:
				throw LDAPInvalidCredentialsException(buffer.str());

			case LDAP_INVALID_DN_SYNTAX:
				throw LDAPInvalidDNSyntaxException(buffer.str());

			case LDAP_INVALID_SYNTAX:
				throw LDAPInvalidSyntaxException(buffer.str());

			case LDAP_LOCAL_ERROR:
				throw LDAPLocalErrorException(buffer.str());

			case LDAP_NAMING_VIOLATION:
				throw LDAPNamingViolationException(buffer.str());

			case LDAP_NO_MEMORY:
				throw LDAPNoMemoryException(buffer.str());

			case LDAP_NO_OBJECT_CLASS_MODS:
				throw LDAPNoObjectClassModsException(buffer.str());

			case LDAP_NO_RESULTS_RETURNED:
				throw LDAPNoResultsReturnedException(buffer.str());

			case LDAP_NO_SUCH_ATTRIBUTE:
				throw LDAPNoSuchAttributeException(buffer.str());

			case LDAP_NO_SUCH_OBJECT:
				throw LDAPNoSuchObjectException(buffer.str());

			case LDAP_NOT_ALLOWED_ON_NONLEAF:
				throw LDAPOpNotAllowedOnNonleafException(buffer.str());

			case LDAP_NOT_ALLOWED_ON_RDN:
				throw LDAPOpNotAllowedOnRDNException(buffer.str());

			case LDAP_NOT_SUPPORTED:
				throw LDAPNotSupportedException(buffer.str());

			case LDAP_OBJECT_CLASS_VIOLATION:
				throw LDAPObjectClassViolationException(buffer.str());

			case LDAP_OPERATIONS_ERROR:
				throw LDAPOperationsErrorException(buffer.str());

			case LDAP_OTHER:
				throw LDAPOtherException(buffer.str());

			case LDAP_PARAM_ERROR:
				throw LDAPParamErrorException(buffer.str());

			case LDAP_PROTOCOL_ERROR:
				throw LDAPProtocolErrorException(buffer.str());

			case LDAP_REFERRAL_LIMIT_EXCEEDED:
				throw LDAPReferralLimitExceededException(buffer.str());

			case LDAP_RESULTS_TOO_LARGE:
				throw LDAPResultsTooLargeException(buffer.str());

			case LDAP_SERVER_DOWN:
				throw LDAPServerDownException(buffer.str());

			case LDAP_SIZELIMIT_EXCEEDED:
				throw LDAPSizeLimitExceededException(buffer.str());

			case LDAP_STRONG_AUTH_REQUIRED:
				throw LDAPStrongAuthRequiredException(buffer.str());

			case LDAP_TIMELIMIT_EXCEEDED:
				throw LDAPTimeLimitExceededException(buffer.str());

			case LDAP_TIMEOUT:
				throw LDAPTimeoutException(buffer.str());

			case LDAP_UNAVAILABLE:
				throw LDAPUnavailableException(buffer.str());

			case LDAP_UNAVAILABLE_CRIT_EXTENSION:
				throw LDAPUnavailableCritExtensionException(buffer.str());

			case LDAP_UNDEFINED_TYPE:
				throw LDAPUndefinedTypeException(buffer.str());

			case LDAP_UNWILLING_TO_PERFORM:
				throw LDAPUnwillingToPerformException(buffer.str());

			case LDAP_USER_CANCELLED:
				throw LDAPUserCancelledException(buffer.str());

			case LDAP_VIRTUAL_LIST_VIEW_ERROR:
				throw LDAPVirtualListViewErrorException(buffer.str());
		}
	}

	//ULONG numberOfEntries;
    
    //numberOfEntries = ldap_count_entries(
    //                    connection_->getConnectionHandle(),    // Session handle
    //                    searchResults);     // Search result
    
    //if(numberOfEntries == NULL)
    //{
    //    printf("ldap_count_entries failed with 0x%0lx \n",errorCode);
    //    ldap_unbind_s(pLdapConnection);
    //    if(pSearchResult != NULL)
    //        ldap_msgfree(pSearchResult);
    //    return -1;
    //} else if(numberOfEntries != 1) {
		// Tratar erro aqui depois.
	//}

	LDAPMessage* pEntry = NULL;
    PCHAR pEntryDN = NULL;
    BerElement* pBer = NULL;
    PCHAR pAttribute = NULL;
    PCHAR* ppValue = NULL;
    ULONG iValue = 0;
    
    pEntry = ldap_first_entry(connection_->ldap_, searchResults);
    
    if( pEntry == NULL )
    {
        //ldap_unbind_s(pLdapConnection);
        //ldap_msgfree(pSearchResult);
        //return -1;
    } else {
		PCHAR dn = ldap_get_dn(connection_->ldap_, pEntry);
	}
                
    // Get the firt attribute name.
    pAttribute = ldap_first_attribute(
                  connection_->ldap_,   // Session handle
                  pEntry,            // Current entry
                  &pBer);            // [out] Current BerElement
    
    // Output the attribute names for the current object
    // and output values.
    while(pAttribute != NULL) {        
        // Get the string values.

        ppValue = ldap_get_values(
                      connection_->ldap_,  // Session Handle
                      pEntry,           // Current entry
                      pAttribute);      // Current attribute

        // Print status if no values are returned (NULL ptr)
        if(ppValue == NULL)
        {
            //printf(": [NO ATTRIBUTE VALUE RETURNED]");
        }

        // Output the attribute values
        else
        {
            iValue = ldap_count_values(ppValue);
            if(!iValue)
            {
               // printf(": [BAD VALUE LIST]");
            }
            else
            {
                // Output the first attribute value
                //printf(": %s", *ppValue);

                // Output more values if available
                ULONG z;
                for(z=1; z<iValue; z++)
                {
                    //printf(", %s", ppValue[z]);
                }
            }
        } 

        // Free memory.
        if(ppValue != NULL)  
            ldap_value_free(ppValue);
        ppValue = NULL;
        ldap_memfree(pAttribute);
        
        // Get next attribute name.
        pAttribute = ldap_next_attribute(
                        connection_->ldap_,   // Session Handle
                        pEntry,            // Current entry
                        pBer);             // Current BerElement
    }
    
    if( pBer != NULL )
        ber_free(pBer,0);
    pBer = NULL;

	std::string uid("a");
	boost::shared_ptr<LDAPUser> user(new LDAPUser(uid, uid, uid));
	return user;
}

}