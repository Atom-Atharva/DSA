// https://leetcode.com/problems/interleaving-string/description/

#include <iostream>
using namespace std;
#include <vector>

// Dynamic Approach
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
        {
            return false;
        }

        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= s1.length(); i++)
        {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int i = 1; i <= s2.length(); i++)
        {
            dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
        }

        for (int i = 1; i <= s1.length(); i++)
        {
            for (int j = 1; j <= s2.length(); j++)
            {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[s1.length()][s2.length()];
    }
};

// Recursive Approach + Memomization
class Solution
{
    bool isInterleave(string s1, string s2, string s3, vector<vector<vector<int>>> &dp, int i, int j, int k)
    {
        // Base Case--
        if (s3.length() == 0)
        {
            return true;
        }
        if (s1.length() == 0)
        {
            return s3 == s2;
        }
        if (s2.length() == 0)
        {
            return s3 == s1;
        }
        if (s3[0] != s1[0] && s3[0] != s2[0])
        {
            return false;
        }
        if (dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }

        // Check First Value--
        bool str1 = (s1[0] == s3[0]) ? isInterleave(s1.substr(1), s2, s3.substr(1), dp, i + 1, j, k + 1) : false;
        bool str2 = (s2[0] == s3[0]) ? isInterleave(s1, s2.substr(1), s3.substr(1), dp, i, j + 1, k + 1) : false;

        return dp[i][j][k] = str1 || str2;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        // Base Case--
        if (s3.length() != s1.length() + s2.length())
        {
            return false;
        }

        vector<vector<vector<int>>> dp(s1.length(), vector<vector<int>>(s2.length(), vector<int>(s3.length(), -1)));

        return isInterleave(s1, s2, s3, dp, 0, 0, 0);
    }
};