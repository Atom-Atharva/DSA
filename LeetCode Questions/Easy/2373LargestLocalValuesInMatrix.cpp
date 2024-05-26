// https://leetcode.com/problems/largest-local-values-in-a-matrix/?envType=daily-question&envId=2024-05-12

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    int getMaxElement(vector<vector<int>> &grid, int x, int y)
    {
        int maxElement = 0;
        for (int i = x; i < x + 3; i++)
        {
            for (int j = y; j < y + 3; j++)
            {
                maxElement = max(maxElement, grid[i][j]);
            }
        }
        return maxElement;
    }

public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<vector<int>> output(n - 2, vector<int>(n - 2));

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                output[i][j] = getMaxElement(grid, i, j);
            }
        }

        return output;
    }
};