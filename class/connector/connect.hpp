#ifndef CONNECT_HPP
#define CONNECT_HPP

#include <boost/asio.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost;

class connector
{
    asio::ip::address_v4 ip;
    int port;

public:
    connector();
    connector(string, int);
    ~connector();

    void setaddress(string);
    asio::ip::tcp::socket *getsock(asio::io_service &);
};

#endif