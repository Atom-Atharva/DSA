// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
    // Using BFS
    bool detectCycle(int i, vector<int> adj[], vector<int> &visited)
    {
        queue<pair<int, int>> nodes;
        nodes.push({i, -1});

        while (!nodes.empty())
        {
            pair<int, int> curr = nodes.front();
            nodes.pop();

            visited[curr.first] = 1;

            for (auto itr : adj[curr.first])
            {
                if (visited[itr] && curr.second != itr)
                {
                    return true;
                }
                else if (!visited[itr])
                {
                    nodes.push({itr, curr.first});
                }
            }
        }

        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);

        // Loop for Island Graphs
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && detectCycle(i, adj, visited))
            {
                return true;
            }
        }

        return false;
    }
};