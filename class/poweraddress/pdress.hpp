#ifndef PDRESS_HPP
#define PDRESS_HPP

#include <iostream>
#include <string>

using namespace std;

const int ADD_KEY = 173;

class poweradd
{
    string rawadd;
    string padd;
    string sparr[4];
    int iparr[4];
    void generatepoweradd();
    void generaterawadd();
    void parseraw();
    void parsepower();

public:
    void setraw(const string &);
    void setpadd(const string &);
    string getraw();
    string getpadd();
};

#endif