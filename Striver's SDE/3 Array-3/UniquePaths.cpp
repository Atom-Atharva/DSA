// https://leetcode.com/problems/unique-paths/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    long long numberOfPaths(int M, int N, vector<vector<int>> &dp)
    {
        // Base Case
        if (M == 0 || N == 0)
        {
            return 0;
        }
        if (M == 1 && N == 1)
        {
            return 1;
        }
        if (dp[M - 1][N - 1] != -1)
        {
            return dp[M - 1][N - 1];
        }

        // Recursive Calls
        int up = numberOfPaths(M - 1, N, dp);
        int left = numberOfPaths(M, N - 1, dp);

        return dp[M - 1][N - 1] = (up + left);
    }

public:
    int uniquePaths(int M, int N)
    {
        vector<vector<int>> dp(M, vector<int>(N, -1));
        return numberOfPaths(M, N, dp);
    }
};