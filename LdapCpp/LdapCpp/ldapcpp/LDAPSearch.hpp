#ifndef LDAP_SEARCH_HPP__
#define LDAP_SEARCH_HPP__

#include <string>
#include <boost/shared_ptr.hpp>
#include <ldapcpp/exception/LDAPExceptions.hpp>
#include <ldapcpp/data/LDAPUser.hpp>
#include <ldapcpp/LDAPConnection.hpp>
#include <vector>

#ifdef LDAP_CPP_EXPORTS
#define LDAP_CPP_API __declspec(dllexport)
#else
#define LDAP_CPP_API __declspec(dllimport)
#endif

#pragma warning (disable: 4290)
namespace ldapcpp {

class LDAPSearch {
public:
	explicit LDAPSearch(const std::string& base, const boost::shared_ptr<LDAPConnection>& connection);
	virtual ~LDAPSearch(void);

	virtual boost::shared_ptr<LDAPUser> search(const std::string& userName);

	virtual std::string getSearchFilter(const std::string& userName) = 0;
	virtual std::vector<std::string> getSearchAttrs() = 0;
private:
	std::string baseDN_;
	boost::shared_ptr<LDAPConnection> connection_;

	LDAPSearch(void);
	LDAPSearch(const LDAPSearch& rhs);
	LDAPSearch& operator=(const LDAPSearch& rhs);
};
}

#endif