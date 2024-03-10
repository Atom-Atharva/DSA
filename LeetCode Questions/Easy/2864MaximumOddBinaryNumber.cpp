// https://leetcode.com/problems/maximum-odd-binary-number/?envType=daily-question&envId=2024-03-01

#include <iostream>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int ones = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                ones++;
            }
        }

        string ans = "";
        ones--;

        for (int i = 0; i < s.length() - 1; i++)
        {
            if (ones)
            {
                ans += '1';
                ones--;
            }
            else
            {
                ans += '0';
            }
        }

        ans += '1';

        return ans;
    }
};