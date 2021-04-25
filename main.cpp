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
    asio::ip::tcp::socket *mysock = NULL;
    if (ans == 'y' || ans == 'Y')
    {
        connected = true;
        cout << "Give Your Friend Address : ";
        cin >> frnd.address;
        poweradd ptor;
        ptor.setpadd(frnd.getaddress());
        frnd.address = ptor.getraw();
        connector connect(frnd.getaddress(), 6767);
        mysock = connect.getsock();
    }
    else
    {
        cout << me.getname() + " , Do you Want a Friend to Connect : (y/n) ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            connected = true;
            acceptor accept(6767);
            me.address = accept.getaddress();
            poweradd rtop;
            rtop.setraw(me.address);
            cout << "\n\nYour Address is : " << rtop.getpadd();
            mysock = accept.accept();
        }
    }

    if (connected)
    {
        // chat here

        if (mysock != NULL)
            delete mysock;
    }
    else
        cout << "\nExiting Without Any Connection\n";
    return 0;
}