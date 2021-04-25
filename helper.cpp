

string getyouraddress()
{
    cout << "Let me decide which interface to connect ? (y/n) : ";
    char x;
    cin >> x;
    string add;
    if (x == 'n' || x == 'N')
    {
        cout << "Okey then , give a working ip : ";
        cin >> add;
    }
    else
    {
        string getsysip = "ifconfig | grep netmask | grep 192 | tr -d \" \" | cut -d \"t\" -f 2 | cut -d \"n\" -f 1 | tr -d \"\\n\" | tr -d \" \" > chat_vat_temp.txt";
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
        add = buffer.substr(0, buffer.size() - 1);
        fin.close();
        std::system("rm chat_vat_temp.txt");
    }

    poweradd myadd;
    myadd.setraw(add);
    return myadd.getpadd();
}