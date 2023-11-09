// https://leetcode.com/problems/count-number-of-homogenous-substrings/description/?envType=daily-question&envId=2023-11-09

#include <iostream>
using namespace std;

class Solution
{
public:
    int countHomogenous(string s)
    {
        long long ans = 0;
        long long count = 1;
        int MOD = 1000000007;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
            {
                count++;
            }
            else
            {
                ans += ((count * (count + 1)) / 2) % MOD;
                count = 1;
            }
        }
        ans += ((count * (count + 1)) / 2) % MOD;

        return ans;
    }
};