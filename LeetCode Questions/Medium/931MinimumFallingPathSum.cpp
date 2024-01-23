// https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

// Dynamic Programming--
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        vector<vector<int>> dp = matrix;

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                int curr = INT_MAX;
                if (j - 1 >= 0)
                {
                    curr = min(curr, matrix[i][j] + dp[i - 1][j - 1]);
                }
                curr = min(curr, matrix[i][j] + dp[i - 1][j]);
                if (j + 1 < matrix.size())
                {
                    curr = min(curr, matrix[i][j] + dp[i - 1][j + 1]);
                }

                dp[i][j] = curr;
            }
        }

        int minFalling = INT_MAX;
        for (int j = 0; j < matrix.size(); j++)
        {
            minFalling = min(minFalling, dp[matrix.size() - 1][j]);
        }

        return minFalling;
    }
};

// Memomization Approach--
/*
class Solution
{
    int minFallingPathSum(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp)
    {
        if (row == matrix.size())
        {
            return 0;
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        int minFalling = INT_MAX;
        if (col - 1 >= 0)
        {
            minFalling = min(minFalling, matrix[row][col - 1] + minFallingPathSum(matrix, row + 1, col - 1, dp));
        }
        minFalling = min(minFalling, matrix[row][col] + minFallingPathSum(matrix, row + 1, col, dp));
        if (col + 1 < matrix.size())
        {
            minFalling = min(minFalling, matrix[row][col + 1] + minFallingPathSum(matrix, row + 1, col + 1, dp));
        }

        return dp[row][col] = minFalling;
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), -1));

        int minFalling = INT_MAX;
        for (int i = 0; i < matrix[0].size(); i++)
        {
            int curr = matrix[0][i] + minFallingPathSum(matrix, 1, i, dp);
            minFalling = min(minFalling, curr);
        }

        return minFalling;
    }
};
*/

// Recursive Approach--
/****
class Solution
{
    int minFallingPathSum(vector<vector<int>> &matrix, int row, int col)
    {
        if (row == matrix.size())
        {
            return 0;
        }

        int minFalling = INT_MAX;
        if (col - 1 >= 0)
        {
            minFalling = min(minFalling, matrix[row][col - 1] + minFallingPathSum(matrix, row + 1, col - 1));
        }
        minFalling = min(minFalling, matrix[row][col] + minFallingPathSum(matrix, row + 1, col));
        if (col + 1 < matrix.size())
        {
            minFalling = min(minFalling, matrix[row][col + 1] + minFallingPathSum(matrix, row + 1, col + 1));
        }

        return minFalling;
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int minFalling = INT_MAX;
        for (int i = 0; i < matrix[0].size(); i++)
        {
            int curr = matrix[0][i] + minFallingPathSum(matrix, 1, i);
            minFalling = min(minFalling, curr);
        }

        return minFalling;
    }
};
*****/