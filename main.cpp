#include "headers.hpp"

int main()
{
    user me;
    user frnd;
    cout << "What is Your Username : ";
    cin >> me.name;
    cout << me.getname() + " , Do You want to connect to your friend : (y/n) ";
    char ans;
    cin >> ans;
    bool connected = false;
    asio::ip::tcp::socket *mysock;
    if (ans == 'y' || ans == 'Y')
    {
        connected = true;
        cout << "Give Your Friend Address : ";
        cin >> frnd.address;
        connector connect(frnd.getaddress(), 6767);
        mysock = connect.getsock();
        return 0;
    }

    cout << me.getname() + " , Do you Want a Friend to Connect : (y/n) ";
    cin >> ans;
    if (ans == 'y' || ans == 'Y')
    {
        connected = true;
        acceptor accept(6767);
        accept.getadd();

        /*  cout << "\nConnect To Me Through Id : " << accept.getaddress();
        mysock = accept();*/
    }

    if (connected)
    {
        // chat here

        delete mysock;
    }
    else
        cout << "\nExiting Without Any Connection\n";
    return 0;
}