// https://leetcode.com/problems/path-with-maximum-gold/description/?envType=daily-question&envId=2024-05-14

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    int checkAllNonZeros(vector<vector<int>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j])
                {
                    count += grid[i][j];
                }
                else
                {
                    return 0;
                }
            }
        }
        return count;
    }

    int grabGold(vector<vector<int>> &grid, int x, int y)
    {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
        {
            return 0;
        }

        int gold = grid[x][y];
        cout << grid[x][y] << endl;
        grid[x][y] = 0;
        int directionX[] = {0, 1, -1, 0};
        int directionY[] = {1, 0, 0, -1};

        int maxGold = gold;
        for (int i = 0; i < 4; i++)
        {
            int newX = x + directionX[i];
            int newY = y + directionY[i];

            int currGold = gold + grabGold(grid, newX, newY);
            maxGold = max(maxGold, currGold);
        }

        grid[x][y] = gold;
        return maxGold;
    }

public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int count = checkAllNonZeros(grid);
        if (count)
        {
            return count;
        }

        int max_gold = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j])
                {
                    int gold = grabGold(grid, i, j);
                    max_gold = max(max_gold, gold);
                }
            }
        }

        return max_gold;
    }
};