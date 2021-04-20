#ifndef CONNECT_CPP
#define CONNECT_CPP

#include "connect.hpp"

namespace nspcc
{
    asio::io_service ioservice;
    system::error_code ec;

#define errormayhappen                                                    \
    if (nspcc::ec.value() != 0)                                           \
    {                                                                     \
        cerr << (string) "\n\nError : " << nspcc::ec.message() << "\n\n"; \
        exit(EXIT_FAILURE);                                               \
    }

}; // namespace nspcc

connector::connector()
{
    int port = 0;
}

connector::connector(string ip, int port) : port(port)
{
    this->ip = asio::ip::address_v4::from_string(ip, nspcc::ec);
    errormayhappen;
}

connector::~connector()
{
}

void connector::setaddress(string ip)
{
    this->ip = asio::ip::address_v4::from_string(ip, nspcc::ec);
    errormayhappen;
}

asio::ip::tcp::socket *connector::getsock()
{
    using namespace nspcc;
    asio::ip::tcp::socket *socket = new asio::ip::tcp::socket(ioservice);
    asio::ip::tcp protocol = asio::ip::tcp::v4();
    socket->open(protocol, ec);
    errormayhappen;
    asio::ip::tcp::endpoint ep(ip, port);
    socket->connect(ep, ec);
    errormayhappen;
    return socket;
}

#endif