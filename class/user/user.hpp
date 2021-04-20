#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>

using namespace std;

class user
{
public:
    string name;
    string address;

    user();
    user(const string );
    user(const string , const string );
    ~user();
    user(const user &);
    user operator=(const user &);
    string getname() const;
    string getaddress() const;
};

#endif