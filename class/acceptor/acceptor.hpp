#ifndef ACCEPTOR_HPP
#define ACCEPTOR_HPP

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;
using namespace boost;

#include "../makeptr/makeptr.hpp"

class acceptor
{
    int port;

public:
    acceptor();
    acceptor(int);
    ~acceptor();

    string getaddress();
    asio::ip::tcp::socket *accept();
};

#endif