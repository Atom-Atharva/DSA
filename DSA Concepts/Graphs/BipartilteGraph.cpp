// https://www.geeksforgeeks.org/problems/bipartite-graph/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
    bool isBipartite(int start, int V, vector<int> adj[], vector<int> &color)
    {
        queue<pair<int, int>> nodes;
        nodes.push({start, 0});

        while (!nodes.empty())
        {
            int node = nodes.front().first;
            int col = nodes.front().second;
            int paint = (col == 0) ? 1 : 0;
            color[node] = col;

            nodes.pop();
            for (auto itr : adj[node])
            {
                if (color[itr] != -1)
                {
                    if (col == color[itr])
                    {
                        return false;
                    }
                    continue;
                }

                nodes.push({itr, paint});
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                bool res = isBipartite(i, V, adj, color);
                if (res == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};