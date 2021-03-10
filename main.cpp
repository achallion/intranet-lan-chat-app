#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using namespace boost;

#include "./helper.cpp"

int main()
{
    string user;
    char ans;
    cout << "What is Your Username : ";
    cin >> user;
    cout << user + " , Do You want to connect to your friend : (y/n) ";
    cin >> ans;
    if (ans == 'y' || ans == 'Y')
    {
        cout << "Give Your Friend Address : ";
        string address;
        cin >> address;
        connecttofriend(address);
        //   iconnectchat();
        return 0;
    }
    cout << user + " , Do you Want a Friend to Connect : (y/n) ";
    cin >> ans;
    if (ans == 'y' || ans == 'Y')
    {
        string address = getyouraddress();
        cout << " Okey , Your address to connecct is : (y/n) ";
        // letfriendconnect();
        //  friendconnectchat();
        return 0;
    }

    cout << "Can't Be Idle , So Exiting ... ";
    return 0;
}