// https://leetcode.com/problems/longest-palindrome/?envType=daily-question&envId=2024-06-04

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int longestPalindrome(string s)
    {
        vector<int> freq(127, 0);
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i]]++;
        }

        int count = 0;
        bool isOdd = false;

        for (int i = 0; i < 127; i++)
        {
            if (freq[i] % 2 == 0)
            {
                count += freq[i];
            }
            else
            {
                isOdd = true;
                count += freq[i] - 1;
            }
        }

        count = (isOdd) ? count + 1 : count;
        return count;
    }
};