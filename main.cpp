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
    if (ans == 'y' || ans == 'Y')
    {
        connected = true;
        cout << "Give Your Friend Address : ";
        cin >> frnd.address;
        asio::ip::tcp::socket mysock = connecttofriend(frnd.getaddress());
        //   iconnectchat();
        return 0;
    }
    else
    {
        connected = true;
        cout << me.getname() + " , Do you Want a Friend to Connect : (y/n) ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            return ec.value();

            cout << "Can't Be Idle , So Exiting ... ";
            return 0;
        }
    }

    if (connected)
    {
    }
    else
        cout << "\nExiting Without Any Connection\n";
    return 0;
}