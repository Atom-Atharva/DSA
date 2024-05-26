// https://leetcode.com/problems/repeated-string-match/

#include <iostream>
using namespace std;

class Solution
{

public:
    int repeatedStringMatch(string a, string b)
    {
        int a_len = a.length();
        int b_len = b.length();

        int n = b_len / a_len;
        int cnt = n;

        string na = "";
        while (cnt--)
        {
            na = na + a;
        }

        // Doesn't Match
        if (na.find(b) != string::npos)
        {
            return n;
        }
        na = na+a;
        if (na.find(b) != string::npos)
        {
            return n+1;
        }
        na = na+a;
        if (na.find(b) != string::npos)
        {
            return n+2;
        }
        

        return -1;

    }
};