#ifndef CRYPT_CPP
#define CRYPT_CPP

#include "crypt.hpp"

namespace encrypt
{
    string xor_(const string &str)
    {
        string ans = "";
        ans += str[0];
        int n = str.length();

        for (int i = 0; i < n - 1; i++)
            ans += str[i] ^ str[i + 1];

        return ans;
    }

    string base64(const string &str)
    {
        string ans;
        int val = 0, valb = -6;
        for (char c : str)
        {
            val = (val << 8) + c;
            valb += 8;
            while (valb >= 0)
            {
                ans.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val >> valb) & 0x3F]);
                valb -= 6;
            }
        }
        if (valb > -6)
            ans.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val << 8) >> (valb + 8)) & 0x3F]);
        while (ans.size() % 4)
            ans.push_back('=');
        return ans;
    }
};

namespace decrypt
{
    string xor_(const string &str)
    {
        string ans = "";
        ans += str[0];
        int n = str.length();

        for (int i = 0; i < n - 1; i++)
            ans += *prev(ans.end()) ^ str[i + 1];

        return ans;
    }
    string base64(const string &str)
    {

        string ans;

        vector<int> T(256, -1);
        for (int i = 0; i < 64; i++)
            T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;

        int val = 0, valb = -8;
        for (char c : str)
        {
            if (T[c] == -1)
                break;
            val = (val << 6) + T[c];
            valb += 6;
            if (valb >= 0)
            {
                ans.push_back(char((val >> valb) & 0xFF));
                valb -= 8;
            }
        }
        return ans;
    }

};

#endif