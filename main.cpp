#include "headers.hpp"

int main()
{
    cout << GRN << "Welcome To End To End Encrypted Intranet Lan System";
    user me;
    user frnd;
    cout << GRN << "\n\nWhat is Your Username : " << YEL;
    cin >> me.name;
    cout << GRN << me.getname() + " , Do You want to connect to your friend : (y/n) " << YEL;
    char ans;
    cin >> ans;
    bool connected = false;
    bool server = false;
    asio::ip::tcp::socket *mysock = NULL;
    if (ans == 'y' || ans == 'Y')
    {
        connected = true;
        cout << GRN << "Give Your Friend Address : " << YEL;
        cin >> frnd.address;
        poweradd ptor;
        ptor.setpadd(frnd.getaddress());
        frnd.address = ptor.getraw();
        connector connect(frnd.getaddress(), 6767);
        mysock = connect.getsock(ioservice);
    }
    else
    {
        cout << GRN << me.getname() + " , Do you Want a Friend to Connect : (y/n) " << YEL;
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            connected = true;
            server = true;
            acceptor accept(6767);
            me.address = accept.getaddress();
            poweradd rtop;
            rtop.setraw(me.address);
            cout << GRN << "\n\nYour Address is : " << YEL << rtop.getpadd() << flush << YEL;
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
            cout << GRN << "\n\nRecieved Encrypted Message : " << RED << rdata;
            cout << "\n"
                 << RST << frnd.name << WHT << " > " << BLU << decrypt::xor_(decrypt::base64(rdata)) << flush;

            cin.clear();
            cin.ignore(INT_MAX, '\n');

            cout << "\n"
                 << RST << me.name << " ( YOU )" << WHT << " > " << BLU << flush;
            getline(cin, sendermsg);
            string sdata = encrypt::base64(encrypt::xor_(sendermsg));
            cout << GRN << "Sending Encrypted Message : " << RED << sdata << flush;
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