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
#include <ldapcpp/exception/LDAPAdminLimitExceededException.hpp>
#include <ldapcpp/exception/LDAPAffectsMultipleDsasException.hpp>
#include <ldapcpp/exception/LDAPAliasDerefProblemException.hpp>
#include <ldapcpp/exception/LDAPAliasProblemException.hpp>
#include <ldapcpp/exception/LDAPAlreadyExistsException.hpp>
#include <ldapcpp/exception/LDAPAttributeOrValueExistsException.hpp>
#include <ldapcpp/exception/LDAPAuthMethodNotSupportedException.hpp>
#include <ldapcpp/exception/LDAPAuthUnknownException.hpp>
#include <ldapcpp/exception/LDAPBusyException.hpp>
#include <ldapcpp/exception/LDAPClientLoopException.hpp>
#include <ldapcpp/exception/LDAPConfidentialityRequiredException.hpp>
#include <ldapcpp/exception/LDAPConnectErrorException.hpp>
#include <ldapcpp/exception/LDAPConstraintViolationException.hpp>
#include <ldapcpp/exception/LDAPControlNotFoundException.hpp>
#include <ldapcpp/exception/LDAPDecodingErrorException.hpp>
#include <ldapcpp/exception/LDAPEncodingErrorException.hpp>
#include <ldapcpp/exception/LDAPException.hpp>
#include <ldapcpp/exception/LDAPFilterErrorException.hpp>
#include <ldapcpp/exception/LDAPInappropriateAuthException.hpp>
#include <ldapcpp/exception/LDAPInappropriateMatchingException.hpp>
#include <ldapcpp/exception/LDAPInitException.hpp>
#include <ldapcpp/exception/LDAPInsufficientRightsException.hpp>
#include <ldapcpp/exception/LDAPInvalidCredentialsException.hpp>
#include <ldapcpp/exception/LDAPInvalidDNSyntaxException.hpp>
#include <ldapcpp/exception/LDAPInvalidSyntaxException.hpp>
#include <ldapcpp/exception/LDAPLocalErrorException.hpp>
#include <ldapcpp/exception/LDAPNamingViolationException.hpp>
#include <ldapcpp/exception/LDAPNoMemoryException.hpp>
#include <ldapcpp/exception/LDAPNoObjectClassModsException.hpp>
#include <ldapcpp/exception/LDAPNoResultsReturnedException.hpp>
#include <ldapcpp/exception/LDAPNoSuchAttributeException.hpp>
#include <ldapcpp/exception/LDAPNoSuchObjectException.hpp>
#include <ldapcpp/exception/LDAPNotSupportedException.hpp>
#include <ldapcpp/exception/LDAPObjectClassViolationException.hpp>
#include <ldapcpp/exception/LDAPOperationsErrorException.hpp>
#include <ldapcpp/exception/LDAPOpNotAllowedOnNonleafException.hpp>
#include <ldapcpp/exception/LDAPOpNotAllowedOnRDNException.hpp>
#include <ldapcpp/exception/LDAPOtherException.hpp>
#include <ldapcpp/exception/LDAPParamErrorException.hpp>
#include <ldapcpp/exception/LDAPProtocolErrorException.hpp>
#include <ldapcpp/exception/LDAPReferralLimitExceededException.hpp>
#include <ldapcpp/exception/LDAPResultsTooLargeException.hpp>
#include <ldapcpp/exception/LDAPServerDownException.hpp>
#include <ldapcpp/exception/LDAPSizeLimitExceededException.hpp>
#include <ldapcpp/exception/LDAPStrongAuthRequiredException.hpp>
#include <ldapcpp/exception/LDAPTimeLimitExceededException.hpp>
#include <ldapcpp/exception/LDAPTimeoutException.hpp>
#include <ldapcpp/exception/LDAPUnavailableCritExtensionException.hpp>
#include <ldapcpp/exception/LDAPUnavailableException.hpp>
#include <ldapcpp/exception/LDAPUndefinedTypeException.hpp>
#include <ldapcpp/exception/LDAPUnwillingToPerformException.hpp>
#include <ldapcpp/exception/LDAPUserCancelledException.hpp>
#include <ldapcpp/exception/LDAPVirtualListViewErrorException.hpp>
