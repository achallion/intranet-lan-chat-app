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


/* FOREGROUND Colours */
#define RST  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x)	"\x1B[1m" x RST
#define UNDL(x)	"\x1B[4m" x RST

// ##########################

string remnl(string str)
{
    int n = str.size(), pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '\n')
            pos = i;
    }
    if (pos != -1)
        str = str.substr(0, pos);
    return str;
}

asio::io_service ioservice;