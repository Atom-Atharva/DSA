// https://leetcode.com/problems/make-the-string-great/description/?envType=daily-question&envId=2024-04-05

#include <iostream>
using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            ans += s[i];
            int n = ans.length() - 1;
            if (n > 0 && (ans[n] - 'a' == ans[n - 1] - 'A' || ans[n] - 'A' == ans[n - 1] - 'a'))
            {
                ans.pop_back();
                ans.pop_back();
            }
        }

        return ans;
    }
};