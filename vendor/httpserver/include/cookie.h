#ifndef HTTP_COOKIE_HPP
#define HTTP_COOKIE_HPP

#include <string>
#include <vector>
#include <map>
#include "datetime.h"
#include "urlcode.h"

namespace http
{
    class Cookie
    {

    public:
        Cookie();
        Cookie *set(std::string key, std::string val, unsigned long exptime = 0,std::string path = "", std::string domain = "",  bool secure = false, bool httponly = true, std::string issamesite = "");
        Cookie *opt(std::string key);
        Cookie *domain(std::string d);
        Cookie *expires(unsigned long e);
        Cookie *path(std::string p);
        Cookie *secure(unsigned char p);
        Cookie *httponly(unsigned char p);
        Cookie *samesite(std::string p);
        std::string get(std::string key);
        std::string &operator[](std::string key);
        std::map<std::string, std::string>::const_iterator begin() const;

        std::map<std::string, std::string>::const_iterator end() const;

        std::map<std::string, std::string>::iterator begin();

        std::map<std::string, std::string>::iterator end();

        std::map<std::string, std::string> getAll();
        std::string makeheader(std::string key);
        void clear();
        bool check(std::string key);

        std::string getDomain(std::string key);
        std::string getPath(std::string key);
        unsigned long getExpires(std::string key);
        unsigned char getSecure(std::string key);
        unsigned char getHttponly(std::string key);
        std::string getSamesite(std::string key);

    public:
        std::map<std::string, std::string> _val;
        std::map<std::string, std::string> _domain;
        std::map<std::string, std::string> _path;
        std::map<std::string, unsigned long> _expires;
        std::map<std::string, unsigned char> _secure;
        std::map<std::string, unsigned char> _httponly;
        std::string curkey;
        std::map<std::string, bool> _set;
        std::map<std::string, std::string> _samesite;
    };
}
#endif