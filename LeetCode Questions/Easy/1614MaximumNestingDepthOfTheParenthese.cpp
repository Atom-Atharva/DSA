// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/?envType=daily-question&envId=2024-04-04

#include <iostream>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int count = 0;

        int dept = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                count++;
            }
            else if (s[i] == ')')
            {
                count--;
            }

            dept = max(dept, count);
        }

        return dept;
    }
};