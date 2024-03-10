// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void dfsTraversal(vector<vector<char>> &grid, int row, int col)
    {
        grid[row][col] = 0;

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int neighbourRow = row + i;
                int neighbourCol = col + j;

                if (neighbourCol < grid[row].size() && neighbourCol >= 0 && neighbourRow < grid.size() && neighbourRow >= 0 && grid[neighbourRow][neighbourCol] == '1')
                {
                    dfsTraversal(grid, neighbourRow, neighbourCol);
                }
            }
        }

        return;
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfsTraversal(grid, i, j);
                }
            }
        }

        return count;
    }
};