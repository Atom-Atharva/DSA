// https://www.geeksforgeeks.org/problems/number-of-enclaves/1

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void dfsFor1s(vector<vector<int>> &grid, int n, int m, int row, int col, vector<vector<int>> &visited)
    {
        visited[row][col] = 1;
        grid[row][col] = 0;

        int pos[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto itr : pos)
        {
            int nX = row + itr[0];
            int nY = col + itr[1];

            if (nX >= 0 && nY >= 0 && nX < n && nY < m && !visited[nX][nY] && grid[nX][nY] == 1)
            {
                dfsFor1s(grid, n, m, nX, nY, visited);
            }
        }

        return;
    }

public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            if (!visited[i][0] && grid[i][0] == 1)
            {
                dfsFor1s(grid, n, m, i, 0, visited);
            }
            if (!visited[i][m - 1] && grid[i][m - 1] == 1)
            {
                dfsFor1s(grid, n, m, i, m - 1, visited);
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (!visited[0][j] && grid[0][j] == 1)
            {
                dfsFor1s(grid, n, m, 0, j, visited);
            }
            if (!visited[n - 1][j] && grid[n - 1][j] == 1)
            {
                dfsFor1s(grid, n, m, n - 1, j, visited);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    count++;
                }
            }
        }

        return count;
    }
};