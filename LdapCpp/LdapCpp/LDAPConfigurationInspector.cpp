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

#include <ldapcpp/config/LDAPConfigurationInspector.hpp>
#include <ldapcpp/config/LDAPConfigurationValidator.hpp>
#include <ldapcpp/config/LDAPBaseDNPolicy.hpp>
#include <ldapcpp/config/LDAPBindPasswordPolicy.hpp>
#include <ldapcpp/config/LDAPBindUserPolicy.hpp>
#include <ldapcpp/config/LDAPServerAddrPolicy.hpp>
#include <ldapcpp/config/LDAPServerPortPolicy.hpp>
#include <ldapcpp/config/LDAPTimeoutPolicy.hpp>
#include <ldapcpp/config/ServerVendorPolicy.hpp>
//#include <ldapcpp/config/LDAPGroupBaseDNPolicy.hpp>

namespace ldapcpp {

LDAPConfigurationInspector::LDAPConfigurationInspector()
{

}

LDAPConfigurationInspector::~LDAPConfigurationInspector()
{

}

void LDAPConfigurationInspector::inspect(const LDAPConfigurationManager& config) throw (LDAPInvalidConfigurationException) {
	LDAPConfigurationValidator<LDAPConfigurationManager, ServerVendorPolicy<LDAPConfigurationManager>, LDAPServerAddrPolicy<LDAPConfigurationManager>, LDAPServerPortPolicy<LDAPConfigurationManager>, LDAPBaseDNPolicy<LDAPConfigurationManager>, LDAPBindUserPolicy<LDAPConfigurationManager>, LDAPBindPasswordPolicy<LDAPConfigurationManager>, LDAPTimeoutPolicy<LDAPConfigurationManager> > validator;
	validator.validate(config);
}

}
