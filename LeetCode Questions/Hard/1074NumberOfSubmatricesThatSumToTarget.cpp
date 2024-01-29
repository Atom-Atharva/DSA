// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/?envType=daily-question&envId=2024-01-28

#include <iostream>
using namespace std;
#include <vector>

// Recursive Approach + Memomization
class Solution
{
    int findSum(vector<vector<int>> &matrix, int row, int col, int m, int n)
    {
        int sum = 0;
        for (int i = row; i < row + m; i++)
        {
            for (int j = col; j < col + n; j++)
            {
                sum += matrix[i][j];
            }
        }
        return sum;
    }

    int numMatrixs(vector<vector<int>> &matrix, int rows, int cols, int target)
    {
        int count = 0;

        // For Each Submatrix
        for (int i = 0; i < matrix.size() - rows + 1; i++)
        {
            for (int j = 0; j < matrix[0].size() - cols + 1; j++)
            {
                // Calculate Sum
                int sum = findSum(matrix, i, j, rows, cols);

                count += (sum == target);
            }
        }

        return count;
    }

    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target, int rows, int cols, vector<vector<int>> &dp)
    {
        // Base Case
        if (rows > matrix.size() || cols > matrix[0].size())
        {
            return 0;
        }
        if (dp[rows - 1][cols - 1] != -1)
        {
            return 0;
        }

        // Check for Target
        int ans = numMatrixs(matrix, rows, cols, target);

        // Recursive Calls
        int rowInc = numSubmatrixSumTarget(matrix, target, rows + 1, cols, dp);
        int colInc = numSubmatrixSumTarget(matrix, target, rows, cols + 1, dp);

        dp[rows - 1][cols - 1] = ans + rowInc + colInc;
        return dp[rows - 1][cols - 1];
    }

public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        return numSubmatrixSumTarget(matrix, target, 1, 1, dp);
    }
};