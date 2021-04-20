#ifndef USER_CPP
#define USER_CPP

#include "user.hpp"

user::user()
{
    name = "";
    address = "";
}

user::user(const string name) : name(name)
{
    address = "";
}

user::user(const string name, const string address) : name(name), address(address)
{
}

user::~user() {}

user::user(const user &user) : name(user.name), address(user.address)
{
}

user user::operator=(const user &user)
{
    this->name = user.name;
    this->address = user.address;
    return *this;
}

string user::getname() const
{
    return name;
}

string user::getaddress() const
{
    return address;
}

#endif