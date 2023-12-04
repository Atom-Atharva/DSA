// https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/?envType=daily-question&envId=2023-12-04

#include <iostream>
using namespace std;

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        string ans = "";
        for (int i = 0; i < num.size(); i++)
        {
            // Substring--
            string sub = num.substr(i, 3);
            if (sub[0] == sub[1] && sub[1] == sub[2])
            {
                // Store Largest--
                if (ans < sub)
                {
                    ans = sub;
                }
            }
        }

        return ans;
    }
};