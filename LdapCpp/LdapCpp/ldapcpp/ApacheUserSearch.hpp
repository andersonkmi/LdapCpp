#ifndef APACHE_USER_SEARCH_HPP__
#define APACHE_USER_SEARCH_HPP__


#include <ldapcpp/LDAPSearch.hpp>

#ifdef LDAP_CPP_EXPORTS
#define LDAP_CPP_API __declspec(dllexport)
#else
#define LDAP_CPP_API __declspec(dllimport)
#endif

namespace ldapcpp {
class ApacheUserSearch : public LDAPSearch {
public:
	explicit ApacheUserSearch(const std::string& base, const boost::shared_ptr<LDAPConnection>& connection);
	virtual ~ApacheUserSearch();

	std::string getSearchFilter(const std::string& userName);
	std::vector<std::string> getSearchAttrs();
private:
	ApacheUserSearch();
	ApacheUserSearch(const ApacheUserSearch&);
	ApacheUserSearch& operator=(const ApacheUserSearch&);
};

}

#endif // !defined(AFX_APACHEUSERSEARCH_HPP__D7EB11CE_9748_4B03_9876_D3489B0BA24E__INCLUDED_)
