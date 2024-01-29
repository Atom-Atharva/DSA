// https://leetcode.com/problems/longest-common-subsequence/description/?envType=daily-question&envId=2024-01-25

#include <iostream>
using namespace std;
#include <vector>

// Dynamic Programming
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // Dynamic Table and Initialisation
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));

        for (int i = 1; i < text1.length() + 1; i++)
        {
            for (int j = 1; j < text2.length() + 1; j++)
            {
                // 2 Cases
                int take = (text1[i - 1] == text2[j - 1]) ? 1 + dp[i - 1][j - 1] : 0;

                int ignore = max(dp[i - 1][j], dp[i][j - 1]);

                dp[i][j] = max(take, ignore);
            }
        }

        return dp[text1.length()][text2.length()];
    }
};

// Memomization Approach
class Solution
{
    int isExist(string s, char c)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == c)
            {
                return i;
            }
        }
        return -1;
    }

    int longestCommonSubsequence(string text1, string text2, vector<vector<int>> &dp, int pos1, int pos2)
    {
        // Base Case
        if (text1.length() == 0 || text2.length() == 0)
        {
            return 0;
        }
        if (dp[pos1][pos2] != -1)
        {
            return dp[pos1][pos2];
        }

        // Recursive Calls
        // 1. Take --> Only when exist in both strings
        int index = isExist(text2, text1[0]);

        int take = (index != -1) ? 1 + longestCommonSubsequence(text1.substr(1), text2.substr(index + 1), dp, pos1 + 1, pos2 + index + 1) : 0;

        // 2. Ignore
        int ignore = longestCommonSubsequence(text1.substr(1), text2, dp, pos1 + 1, pos2);

        return dp[pos1][pos2] = max(take, ignore);
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return longestCommonSubsequence(text1, text2, dp, 0, 0);
    }
};

// Recursive Approach
class Solution
{
    int isExist(string s, char c)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == c)
            {
                return i;
            }
        }
        return -1;
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // Base Case
        if (text1.length() == 0 || text2.length() == 0)
        {
            return 0;
        }

        // Recursive Calls
        // 1. Take --> Only when exist in both strings
        int index = isExist(text2, text1[0]);

        int take = (index != -1) ? 1 + longestCommonSubsequence(text1.substr(1), text2.substr(index + 1)) : 0;

        // 2. Ignore
        int ignore = longestCommonSubsequence(text1.substr(1), text2);

        return max(take, ignore);
    }
};