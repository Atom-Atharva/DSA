// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/?envType=daily-question&envId=2024-08-11

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Depth First Search
    void dfs(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &visited)
    {
        visited[x][y] = 1;

        for (int i = 0; i < 4; i++)
        {
            int newX = x + directions[i].first;
            int newY = y + directions[i].second;

            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 1 && !visited[newX][newY])
            {
                dfs(grid, newX, newY, visited);
            }
        }

        return;
    }

    // Number Of Islands
    int numberOfIslands(vector<vector<int>> &grid)
    {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] && !visited[i][j])
                {
                    count++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return count;
    }

public:
    int minDays(vector<vector<int>> &grid)
    {
        // Number Of Islands
        int islands = numberOfIslands(grid);

        // If Disconnected => Return 0
        if (islands != 1)
        {
            return 0;
        }

        // Check For 1 => DISCONNECT => Return 1
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    int islands = numberOfIslands(grid);
                    if (islands != 1)
                    {
                        return 1;
                    }

                    grid[i][j] = 1;
                }
            }
        }

        // Else Return 2
        return 2;
    }
};