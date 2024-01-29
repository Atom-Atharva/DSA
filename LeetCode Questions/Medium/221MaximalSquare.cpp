// https://leetcode.com/problems/maximal-square/description/

#include <iostream>
using namespace std;
#include <vector>

// Recursive Approach + Memomization
class Solution
{
    int maximalSquare(vector<vector<char>> &matrix, int row, int col, int &maxSq, vector<vector<int>> &dp)
    {
        // Base Case
        if (row >= matrix.size() || col >= matrix[0].size())
        {
            return 0;
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        // Recursive Calls
        int right = maximalSquare(matrix, row, col + 1, maxSq, dp);
        int down = maximalSquare(matrix, row + 1, col, maxSq, dp);
        int diag = maximalSquare(matrix, row + 1, col + 1, maxSq, dp);

        if (matrix[row][col] != '1')
        {
            return 0;
        }
        int ans = 1 + min(right, min(down, diag));
        maxSq = max(maxSq, ans);
        return dp[row][col] = ans;
    }

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));

        int maxSq = 0;
        maximalSquare(matrix, 0, 0, maxSq, dp);
        return maxSq * maxSq;
    }
};