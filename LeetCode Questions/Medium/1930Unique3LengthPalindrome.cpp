// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2023-11-14

#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int ans = 0;

        unordered_map<char, int> endpts;
        for (int i = 0; i < s.length() - 2; i++)
        {
            if (endpts.count(s[i]) > 0)
            {
                continue;
            }

            unordered_map<char, int> middle;
            int count = 0;
            int add = 0;
            for (int j = i + 1; j < s.length(); j++)
            {
                if (s[i] == s[j])
                {
                    add = count;
                }
                if (middle.count(s[j]) == 0)
                {
                    count++;
                }
                middle[s[j]]++;
            }
            ans += add;
            endpts[s[i]]++;
        }

        return ans;
    }
};