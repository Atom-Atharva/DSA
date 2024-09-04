// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/?envType=daily-question&envId=2024-09-03

#include <iostream>
using namespace std;

class Solution
{
    int getSumofDigits(int curr)
    {
        int ans = 0;
        while (curr)
        {
            int rem = curr % 10;
            ans += rem;
            curr /= 10;
        }

        return ans;
    }

public:
    int getLucky(string s, int k)
    {
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int curr = s[i] - 'a' + 1;
            ans = getSumofDigits(curr);
        }
        k--;

        while (k--)
        {
            int curr = ans;
            ans = getSumofDigits(curr);
        }

        return ans;
    }
};