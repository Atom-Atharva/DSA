// https://leetcode.com/problems/edit-distance/

// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

#include <iostream>
using namespace std;
#include <vector>

// Method 3: Dynamic Programming--
class Solution
{
public:
    int editDistance(string s, string t)
    {
        // Form DP table--
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));

        // Fill Initial Cell--
        dp[0][0] = 0;

        // Fill First Row--
        for (int i = 1; i <= s.size(); i++)
        {
            dp[i][0] = i;
        }

        // Fill First Column--
        for (int i = 1; i <= t.size(); i++)
        {
            dp[0][i] = i;
        }

        // Fill Remaining Cells--
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                // Check if current element is same--
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    int insert = 1 + dp[i][j - 1];
                    int remove = 1 + dp[i - 1][j];
                    int replace = 1 + dp[i - 1][j - 1];

                    dp[i][j] = min(insert, min(remove, replace));
                }
            }
        }

        return dp[s.size()][t.size()];
    }
};

// Method 2: Using Memomization--
class Solution
{
    int edit(string s, string t, vector<vector<int>> &dp)
    {
        // Base Case--
        if (s.size() == 0 || t.size() == 0)
        {
            return max(s.size(), t.size());
        }
        if (s == t)
        {
            return 0;
        }
        if (dp[s.size()][t.size()] != -1)
        {
            return dp[s.size()][t.size()];
        }

        // Check if First Character Matches--
        if (s[0] == t[0])
        {
            // Check for remaining string--
            return dp[s.size()][t.size()] = edit(s.substr(1), t.substr(1), dp);
        }

        // Do 3 Operations--
        // 1. Insert:
        int insert = 1 + edit(s, t.substr(1), dp);

        // 2. Remove:
        int remove = 1 + edit(s.substr(1), t, dp);

        // 3. Replace:
        int replace = 1 + edit(s.substr(1), t.substr(1), dp);

        return dp[s.size()][t.size()] = min(insert, min(remove, replace));
    }

public:
    int editDistance(string s, string t)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        return edit(s, t, dp);
    }
};

// Method 1: Using Recursion--
// TLE
class Solution
{
public:
    int editDistance(string s, string t)
    {
        // Base Case--
        if (s.size() == 0 || t.size() == 0)
        {
            return max(s.size(), t.size());
        }
        if (s == t)
        {
            return 0;
        }

        // Check if First Character Matches--
        if (s[0] == t[0])
        {
            // Check for remaining string--
            return editDistance(s.substr(1), t.substr(1));
        }

        // Do 3 Operations--
        // 1. Insert:
        int insert = 1 + editDistance(s, t.substr(1));

        // 2. Remove:
        int remove = 1 + editDistance(s.substr(1), t);

        // 3. Replace:
        int replace = 1 + editDistance(s.substr(1), t.substr(1));

        return min(insert, min(remove, replace));
    }
};
