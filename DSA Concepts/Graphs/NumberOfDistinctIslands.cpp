// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <queue>

class Solution
{

    void islandFormDFS(vector<vector<int>> &grid, vector<vector<int>> &visited, int row, int col, int startRow, int startCol, vector<pair<int, int>> &island)
    {
        pair<int, int> curr = {row, col};
        visited[curr.first][curr.second] = 1;

        island.push_back({curr.first - startRow, curr.second - startCol});

        int posX[] = {-1, 0, 1, 0};
        int posY[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++)
        {
            int nX = curr.first + posX[i];
            int nY = curr.second + posY[i];

            if (nX >= 0 && nY >= 0 && nX < grid.size() && nY < grid[0].size() && !visited[nX][nY] && grid[nX][nY] == 1)
            {
                islandFormDFS(grid, visited, nX, nY, startRow, startCol, island);
            }
        }

        return;
    }

    vector<pair<int, int>> islandFormBFS(vector<vector<int>> &grid, vector<vector<int>> &visited, int row, int col)
    {
        vector<pair<int, int>> output;

        queue<pair<int, int>> nodes;
        nodes.push({row, col});

        while (!nodes.empty())
        {
            pair<int, int> curr = nodes.front();
            nodes.pop();
            visited[curr.first][curr.second] = 1;

            output.push_back({curr.first - row, curr.second - col});

            int posX[] = {-1, 0, 1, 0};
            int posY[] = {0, -1, 0, 1};

            for (int i = 0; i < 4; i++)
            {
                int nX = curr.first + posX[i];
                int nY = curr.second + posY[i];

                if (nX >= 0 && nY >= 0 && nX < grid.size() && nY < grid[0].size() && !visited[nX][nY] && grid[nX][nY] == 1)
                {
                    nodes.push({nX, nY});
                }
            }
        }

        return output;
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        // Stores only unique values --> Also able to store vectors
        set<vector<pair<int, int>>> islands;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    // vector<pair<int, int>> island = islandFormBFS(grid, visited, i, j);
                    vector<pair<int, int>> island;
                    islandFormDFS(grid, visited, i, j, i, j, island);
                    islands.insert(island);
                }
            }
        }

        return islands.size();
    }
};