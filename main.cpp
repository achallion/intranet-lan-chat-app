#include "headers.hpp"

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

int main()
{
    cout << "Welcome To End To End Encrypted Intranet Lan System";
    user me;
    user frnd;
    cout << "\n\nWhat is Your Username : ";
    cin >> me.name;
    cout << me.getname() + " , Do You want to connect to your friend : (y/n) ";
    char ans;
    cin >> ans;
    bool connected = false;
    bool server = false;
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
        mysock = connect.getsock(ioservice);
    }
    else
    {
        cout << me.getname() + " , Do you Want a Friend to Connect : (y/n) ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            connected = true;
            server = true;
            acceptor accept(6767);
            me.address = accept.getaddress();
            poweradd rtop;
            rtop.setraw(me.address);
            cout << "\n\nYour Address is : " << rtop.getpadd() << flush;
            mysock = accept.accept(ioservice);
        }
    }

    // **********Send And Recieve

    if (connected)
    {

        if (server)
        {
            rw::send(mysock, me.name);
            frnd.name = remnl(rw::recieve(mysock));
            string temp = "HI " + frnd.name;
            rw::send(mysock, encrypt::base64(encrypt::xor_(temp)));
        }
        else
        {
            frnd.name = remnl(rw::recieve(mysock));
            rw::send(mysock, me.name);
        }

        string sendermsg = "";

        while (sendermsg != "exit")
        {
            string recvddata = remnl(rw::recieve(mysock));
            string rdata = remnl(recvddata);
            cout << "\n\nRecieved Encrypted Message : " << rdata;
            cout << "\n"
                 << frnd.name << " > " << decrypt::xor_(decrypt::base64(rdata)) << flush;

            cin.clear();
            cin.ignore(INT_MAX, '\n');

            cout << "\n"
                 << me.name << " ( YOU ) > " << flush;
            getline(cin, sendermsg);
            string sdata = encrypt::base64(encrypt::xor_(sendermsg));
            cout << "Sending Encrypted Message : " << sdata << flush;
            rw::send(mysock, sdata);
        }

        // ##################

        if (mysock != NULL)
        {
            mysock->close();
            delete mysock;
        }
    }
    else
        cout << "\nExiting Without Any Connection\n";
    return 0;
}