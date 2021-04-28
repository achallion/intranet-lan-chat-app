#ifndef CRYPT_HPP
#define CRYPT_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace encrypt
{
    string xor_(const string &);
    string base64(const string &);
};

namespace decrypt
{
    string xor_(const string &);
    string base64(const string &);

};

#endif