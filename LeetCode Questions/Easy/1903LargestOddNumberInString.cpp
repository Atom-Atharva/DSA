// https://leetcode.com/problems/largest-odd-number-in-string/description/?envType=daily-question&envId=2023-12-07

#include <iostream>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        string odd = "";
        for (int i = num.size() - 1; i >= 0; i--)
        {
            // First Odd Digit--
            if ((num[i] - '0') % 2 != 0)
            {
                odd = num.substr(0, i + 1);
                break;
            }
        }

        return odd;
    }
};