#ifndef ACCEPTOR_HPP
#define ACCEPTOR_HPP

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include "../makeptr/makeptr.hpp"

using namespace std;
using namespace boost;

class acceptor
{
    int port;

public:
    acceptor();
    acceptor(int);
    ~acceptor();

    string getaddress();
};

#endif