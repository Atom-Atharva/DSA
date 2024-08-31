// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/?envType=daily-question&envId=2024-08-29

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void dfs(int index, vector<vector<int>> &stones, vector<int> &visited)
    {
        // Mark Curr Visited
        visited[index] = 1;

        // Go to next stone on either same row or same col (unvisited)
        for (int i = 0; i < stones.size(); i++)
        {
            if ((stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1]) && !visited[i])
            {
                dfs(i, stones, visited);
            }
        }

        return;
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        // Visited Array
        vector<int> visited(stones.size(), 0);

        // Find Number of Groups
        int groups = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            if (!visited[i])
            {
                groups++;
                dfs(i, stones, visited);
            }
        }

        // Total stones - Number of Groups
        return stones.size() - groups;
    }
};