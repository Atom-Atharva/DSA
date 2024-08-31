// https: // leetcode.com/problems/regions-cut-by-slashes/description/?envType=daily-question&envId=2024-08-10

//******************** GOOGLE LEVEL QUESTION ***************************//

#include <iostream>
using namespace std;
#include <vector>

// NUMBER OF ISLANDS (ADV)
class Solution
{
    // Make Canvas
    void updateCanvas(vector<string> &grid, vector<vector<int>> &canvas)
    {
        // '/' => [[001],[010],[100]]
        // '\' => [[100],[010],[001]]
        // ' ' => [[000],[000],[000]]
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].length(); j++)
            {
                if (grid[i][j] == '/')
                {
                    canvas[3 * i][3 * j + 2] = 1;
                    canvas[3 * i + 1][3 * j + 1] = 1;
                    canvas[3 * i + 2][3 * j] = 1;
                }
                else if (grid[i][j] == '\\')
                {
                    canvas[3 * i][3 * j] = 1;
                    canvas[3 * i + 1][3 * j + 1] = 1;
                    canvas[3 * i + 2][3 * j + 2] = 1;
                }
            }
        }

        return;
    }

    // Directions
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // DFS on 0s
    void dfs(vector<vector<int>> &canvas, int x, int y, vector<vector<int>> &visited)
    {
        // Visit Current Node
        visited[x][y] = 1;

        // Travel to Next Nodes
        for (int i = 0; i < directions.size(); i++)
        {
            int newX = x + directions[i].first;
            int newY = y + directions[i].second;

            if (newX >= 0 && newX < canvas.size() && newY >= 0 && newY < canvas[0].size() && canvas[newX][newY] == 0 && !visited[newX][newY])
            {
                dfs(canvas, newX, newY, visited);
            }
        }

        return;
    }

    // Count Number of Islands
    int numberOfIslands(vector<vector<int>> &canvas)
    {
        int count = 0;

        vector<vector<int>> visited(canvas.size(), vector<int>(canvas[0].size(), 0));
        for (int i = 0; i < canvas.size(); i++)
        {
            for (int j = 0; j < canvas[i].size(); j++)
            {
                if (canvas[i][j] == 0 && !visited[i][j])
                {
                    // DFS for ISLAND
                    count++;
                    dfs(canvas, i, j, visited);
                }
            }
        }

        return count;
    }

public:
    int regionsBySlashes(vector<string> &grid)
    {
        // ROW = grid.size();
        int rows = grid.size();

        // COL = grid[0].size();
        int cols = grid[0].size();

        // Make canvas grid => [row*3, col*3]
        // Initialize it with 0
        vector<vector<int>> canvas(rows * 3, vector<int>(cols * 3, 0));

        // Update Canvas
        updateCanvas(grid, canvas);

        // Connected Regions With 0 ~ Return Number of Islands
        return numberOfIslands(canvas);
    }
};