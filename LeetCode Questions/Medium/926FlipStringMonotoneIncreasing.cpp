// https://leetcode.com/problems/flip-string-to-monotone-increasing/

#include <iostream>
using namespace std;

// Method: Har Iteration mai minimum nikal rahe hai taki minimum convertions hi ho
//******************************** Good Question *******************************************//

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        bool flag = 0;
        int ones = 0;
        int zeros = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1' && !flag)
            {
                flag = 1;
            }

            if (s[i] == '0' && flag)
            {
                zeros++;
            }
            if (s[i] == '1' && flag)
            {
                ones++;
            }

            zeros = min(ones, zeros);
        }

        return zeros;
    }
};
