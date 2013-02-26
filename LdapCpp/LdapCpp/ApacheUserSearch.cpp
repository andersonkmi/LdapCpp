// ApacheUserSearch.cpp: implementation of the ApacheUserSearch class.
//
//////////////////////////////////////////////////////////////////////

#include <ldapcpp/ApacheUserSearch.hpp>
#include <sstream>

namespace ldapcpp {

ApacheUserSearch::ApacheUserSearch(const std::string& base, const boost::shared_ptr<LDAPConnection>& connection) : LDAPSearch(base, connection) {

}

ApacheUserSearch::~ApacheUserSearch() {

}

std::string ApacheUserSearch::getSearchFilter(const std::string& userName) {
	std::ostringstream filter;
	filter << "(&(uid=" << userName << ")(objectclass=person))";
	return filter.str();
}

std::vector<std::string> ApacheUserSearch::getSearchAttrs() {
	std::vector<std::string> attributes;
	attributes.push_back("displayName");
	attributes.push_back("sn");
	attributes.push_back("cn");

	return attributes;
}

}
