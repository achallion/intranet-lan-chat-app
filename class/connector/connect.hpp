#ifndef CONNECT_HPP
#define CONNECT_HPP

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include "../makeptr/makeptr.hpp"

using namespace std;
using namespace boost;

class connector
{
    asio::ip::address_v4 ip;
    int port;

public:
    connector();
    connector(string ip, int port);
    ~connector();

    void setaddress(string);
    asio::ip::tcp::socket* getsock();
};

#endif