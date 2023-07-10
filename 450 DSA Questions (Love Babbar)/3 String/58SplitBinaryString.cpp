// https://leetcode.com/problems/count-binary-substrings/

// Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

// Substrings that occur multiple times are counted the number of times they occur.

#include <iostream>
using namespace std;

// Using Recursion--
class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int prev = 0;
        int count = 1;
        int ans = 0;

        for (int i = 1; i < s.size(); i++)
        {
            // Count Same elements--
            if (s[i] == s[i - 1])
            {
                count++;
            }
            else
            {
                prev = count;
                count = 1;
            }

            // Check if grouped--
            if (count <= prev)
            {
                ans++;
            }
            else
            {
                prev = 0;
            }
        }

        return ans;
    }
};