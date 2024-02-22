// https://leetcode.com/problems/palindrome-partitioning/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    // Check Palindrome
    bool isPalindrome(string s)
    {
        for (int i = 0; i < s.length() / 2; i++)
        {
            if (s[i] != s[s.length() - 1 - i])
            {
                return false;
            }
        }

        return true;
    }

    void partition(string s, vector<vector<string>> &ans, vector<string> &curr)
    {
        // Base Case
        if (s.length() == 0)
        {
            ans.push_back(curr);
            return;
        }

        string palindrome = "";
        for (int i = 0; i < s.length(); i++)
        {
            // Find Partitions
            // Call Recursion
            palindrome += s[i];
            if (isPalindrome(palindrome))
            {
                curr.push_back(palindrome);
                partition(s.substr(i + 1), ans, curr);
                curr.pop_back();
            }
        }

        return;
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> curr;
        partition(s, ans, curr);

        return ans;
    }
};