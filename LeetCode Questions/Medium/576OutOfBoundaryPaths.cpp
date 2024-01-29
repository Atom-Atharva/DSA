// https://leetcode.com/problems/out-of-boundary-paths/description/?envType=daily-question&envId=2024-01-26

#include <iostream>
using namespace std;
#include <vector>


// Memomization
class Solution
{
    int M = 1e9 + 7;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>> &dp)
    {
        // Base Case
        if (startColumn < 0 || startColumn >= n || startRow < 0 || startRow >= m)
        {
            return 1;
        }
        if (maxMove == 0)
        {
            return 0;
        }
        if (dp[startRow][startColumn][maxMove - 1] != -1)
        {
            return dp[startRow][startColumn][maxMove - 1];
        }

        // Recursive Calls
        int left = findPaths(m, n, maxMove - 1, startRow, startColumn - 1, dp);
        int right = findPaths(m, n, maxMove - 1, startRow, startColumn + 1, dp);
        int up = findPaths(m, n, maxMove - 1, startRow - 1, startColumn, dp);
        int down = findPaths(m, n, maxMove - 1, startRow + 1, startColumn, dp);

        return dp[startRow][startColumn][maxMove - 1] = ((left + right) % M + (up + down) % M) % M;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove, -1)));

        return findPaths(m, n, maxMove, startRow, startColumn, dp);
    }
};