// https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{

public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, pair<int, int>>> pos;

        int freshOranges = 0;
        // Find All Rotten Oranges
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    pos.push({i, {j, 0}});
                }
                else if (grid[i][j] == 1)
                {
                    freshOranges++;
                }
            }
        }

        int time = 0;
        while (!pos.empty())
        {
            pair<int, pair<int, int>> curr = pos.front();
            time = max(time, curr.second.second);
            pos.pop();

            int moves[4][2] = {{-1, 0},
                               {1, 0},
                               {0, -1},
                               {0, 1}};

            for (int i = 0; i < 4; i++)
            {
                int nRow = curr.first + moves[i][0];
                int nCol = curr.second.first + moves[i][1];
                int time = curr.second.second + 1;

                if (nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size() && grid[nRow][nCol] == 1)
                {
                    grid[nRow][nCol] = 2;
                    pos.push({nRow, {nCol, time}});
                    freshOranges--;
                }
            }
        }

        return (freshOranges > 0) ? -1 : time;
    }
};