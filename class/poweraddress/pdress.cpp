#ifndef PDRESS_CPP
#define PDRESS_CPP

#include "pdress.hpp"

void poweradd::setraw(const string &str)
{
    rawadd = str;
    generatepoweradd();
}

void poweradd::setpadd(const string &str)
{
    padd = str;
    generaterawadd();
}

string poweradd::getraw()
{
    return rawadd;
}

string poweradd::getpadd()
{
    return padd;
}

void poweradd::generatepoweradd()
{
    parseraw();
    padd = "";
    for (int i = 0; i < 4; i++)
    {
        sparr[i] = to_string(iparr[i] - ADD_KEY);
        string newbuf = "";
        for (int j = 0; j < sparr[i].size(); j++)
            newbuf += (sparr[i][j] == '5' ? '#' : sparr[i][j]);

        sparr[i] = newbuf;
        padd += (sparr[i] + '5');
    }
    padd = padd.substr(0, padd.size() - 1);
}

void poweradd::generaterawadd()
{
    parsepower();
    rawadd = "";
    for (int i = 0; i < 4; i++)
    {
        string newbuf = "";
        for (int j = 0; j < sparr[i].size(); j++)
            newbuf += (sparr[i][j] == '#' ? '5' : sparr[i][j]);
        iparr[i] = stoi(newbuf) + ADD_KEY;
        rawadd += (to_string(iparr[i]) + '.');
    }
    rawadd = rawadd.substr(0, rawadd.size() - 1);
}

void poweradd::parseraw()
{
    int j = 0;
    string buff = "";
    for (int i = 0; i < rawadd.size(); i++)
    {
        if (rawadd[i] == '.')
        {
            iparr[j++] = stoi(buff);
            buff = "";
            continue;
        }
        buff += rawadd[i];
    }
    iparr[j] = stoi(buff);
}

void poweradd::parsepower()
{
    int j = 0;
    string buff = "";
    for (int i = 0; i < padd.size(); i++)
    {
        if (padd[i] == '5')
        {

            sparr[j++] = buff;
            buff = "";
            continue;
        }
        buff += padd[i];
    }
    sparr[j] = buff;
}

#endif