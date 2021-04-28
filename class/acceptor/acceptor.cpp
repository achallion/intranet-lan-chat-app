#ifndef ACCEPTOR_CPP
#define ACCEPTOR_CPP

#include "acceptor.hpp"

namespace nspac
{
    system::error_code ec;

#define errormayhappen                                                    \
    if (nspac::ec.value() != 0)                                           \
    {                                                                     \
        cerr << (string) "\n\nError : " << nspac::ec.message() << "\n\n"; \
        exit(EXIT_FAILURE);                                               \
    }

}; // namespace nspac

acceptor::acceptor()
{
}

acceptor::acceptor(int port) : port(port)
{
}

acceptor::~acceptor()
{
}

string acceptor::getaddress()
{
    cout << GRN << "\n\nLet me decide which interface to connect ? (y/n) : " << YEL;
    char x;
    cin >> x;
    string rawadd;
    if (x == 'n' || x == 'N')
    {
        cout <<GRN<< "Okey then , give a working wireless ip : " << YEL;
        cin >> rawadd;
    }
    else
    {
        string getsysip = "ifconfig wlan0 | grep \"inet \" | tr -d \" \" | cut -d \"t\" -f 2 | cut -d \"n\" -f 1 > chat_vat_temp.txt";
        std::system(getsysip.c_str());
        // pickup ip from chat_vat_temp.txt
        ifstream fin("chat_vat_temp.txt");
        string buffer = "";
        char x;
        while (!fin.eof())
        {
            x = fin.get();
            buffer += x;
        }
        rawadd = buffer.substr(0, buffer.size() - 1);
        fin.close();
        std::system("rm chat_vat_temp.txt");
    }
    return rawadd;
}

asio::ip::tcp::socket *acceptor::accept(asio::io_service &ioservice)
{
    using namespace nspac;
    asio::ip::tcp::acceptor getter(ioservice);
    getter.open(asio::ip::tcp::v4(), ec);
    errormayhappen;
    getter.bind(asio::ip::tcp::endpoint(asio::ip::address_v4::any(), port), ec);
    errormayhappen;
    getter.listen(3, ec);
    errormayhappen;
    asio::ip::tcp::socket *conn = new asio::ip::tcp::socket(ioservice);
    getter.accept(*conn, ec);
    errormayhappen;

    getter.close();
    return conn;
}

#endif