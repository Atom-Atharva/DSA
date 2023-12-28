// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/?envType=daily-question&envId=2023-12-24

#include <iostream>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int st_0 = 0;
        // Start With 0
        for (int i = 0; i < s.length(); i++)
        {
            if (i % 2 == 0 && s[i] == '1')
            {
                st_0++;
            }
            else if (i % 2 != 0 && s[i] == '0')
            {
                st_0++;
            }
        }

        int st_1 = 0;
        // Start With 1
        for (int i = 0; i < s.length(); i++)
        {
            if (i % 2 != 0 && s[i] == '1')
            {
                st_1++;
            }
            else if (i % 2 == 0 && s[i] == '0')
            {
                st_1++;
            }
        }

        // Minimum of Both
        return min(st_1,st_0);
    }
};