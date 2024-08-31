// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int minInsertions(string s)
    {
        // Initialise DP
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));

        for (int i = s.length() - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < s.length(); j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][s.length() - 1];
    }
};

// Method 2: Memomization
class SolutionMemo
{
    int minInsertions(string &s, int i, int j, vector<vector<int>> &dp)
    {
        // Base Case
        if (i >= j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s[i] == s[j])
        {
            return dp[i][j] = minInsertions(s, i + 1, j - 1, dp);
        }

        // Recursive Calls
        int left = minInsertions(s, i + 1, j, dp);
        int right = minInsertions(s, i, j - 1, dp);

        return dp[i][j] = 1 + min(left, right);
    }

public:
    int minInsertions(string s)
    {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return minInsertions(s, 0, s.length() - 1, dp);
    }
};

// Method 1: Recursion
class SolutionRec
{
    int minInsertions(string s, int i, int j)
    {
        // Base Case
        if (i > j)
        {
            return 0;
        }
        if (s[i] == s[j])
        {
            return minInsertions(s, i + 1, j - 1);
        }

        // Recursive Calls
        int left = minInsertions(s, i + 1, j) + 1;
        int right = minInsertions(s, i, j - 1) + 1;

        return min(left, right);
    }

public:
    int minInsertions(string s)
    {
        int i = 0, j = s.length() - 1;
        return minInsertions(s, i, j);
    }
};