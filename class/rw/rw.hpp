#ifndef RW_HPP
#define RW_HPP

#include <iostream>
#include <boost/asio.hpp>
#include <string>

using namespace std;
using namespace boost;

#include "../user/user.hpp"

namespace rw
{
    string recieve(asio::ip::tcp::socket *socket);
    void send(asio::ip::tcp::socket *socket, const string &message);

};

#endif