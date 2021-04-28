#ifndef RW_CPP
#define RW_CPP

#include "rw.hpp"

namespace rw
{
    string recieve(asio::ip::tcp::socket *socket)
    {
        asio::streambuf buf;
        read_until(*socket, buf, "\n");
        string data = asio::buffer_cast<const char *>(buf.data());
        return data;
    }

    void send(asio::ip::tcp::socket *socket, const string &message)
    {
        asio::write(*socket, asio::buffer(message + "\n"));
    }

};

#endif