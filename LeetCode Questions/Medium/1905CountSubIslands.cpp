// https://leetcode.com/problems/count-sub-islands/description/?envType=daily-question&envId=2024-08-28

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // DFS on GRID 2
    bool dfs(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2, int m, int n)
    {
        if (grid1[i][j] != 1)
        {
            return false;
        }

        grid2[i][j] = 0;
        bool isIsland = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + directions[k][0];
            int y = j + directions[k][1];

            if (x < m && x >= 0 && y < n && y >= 0 && grid2[x][y])
            {
                bool curr = dfs(x, y, grid1, grid2, m, n);
                if (!curr)
                {
                    isIsland &= false;
                }
            }
        }

        return isIsland;
    }

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid1.size();
        int n = grid1[0].size();

        int subIslands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1)
                {
                    bool subIsland = dfs(i, j, grid1, grid2, m, n);
                    if (subIsland)
                    {
                        subIslands++;
                    }
                }
            }
        }

        return subIslands;
    }
};