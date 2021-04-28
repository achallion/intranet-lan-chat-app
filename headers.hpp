#include <iostream>
#include <boost/asio.hpp>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
using namespace boost;

#include "class/poweraddress/pdress.hpp"
#include "class/user/user.hpp"
#include "class/connector/connect.hpp"
#include "class/acceptor/acceptor.hpp"
#include "class/rw/rw.hpp"
#include "class/crypt/crypt.hpp"

asio::io_service ioservice;