// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

#include <string>
using namespace std;
#include <vector>

class Solution
{
    // Modulo for rounding down
    int M = 1e9 + 7;

    long long int countPS(string str, int l, int r, vector<vector<int>> &dp)
    {
        // Base Case--
        if (l > r)
        {
            return 0;
        }
        if (l == r)
        {
            return 1;
        }
        if (dp[l][r] != -1)
        {
            return dp[l][r];
        }

        if (str[l] == str[r])
        {
            return dp[l][r] = (countPS(str, l + 1, r, dp) + countPS(str, l, r - 1, dp) + 1) % M;
        }
        else
        {
            return dp[l][r] = (countPS(str, l + 1, r, dp) + countPS(str, l, r - 1, dp) - countPS(str, l + 1, r - 1, dp)) % M;
        }
    }

public:
    /*You are required to complete below method */
    long long int countPS(string str)
    {
        // Memomization Table
        vector<vector<int>> dp(str.length(), vector<int>(str.length(), -1));

        return countPS(str, 0, str.length() - 1, dp) % M;
    }
};