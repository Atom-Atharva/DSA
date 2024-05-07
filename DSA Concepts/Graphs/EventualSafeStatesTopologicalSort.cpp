// https://www.geeksforgeeks.org/problems/eventual-safe-states/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

class Solution
{
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // Inverse Graph
        vector<int> adjInverse[V];
        for (int i = 0; i < V; i++)
        {
            for (auto itr : adj[i])
            {
                adjInverse[itr].push_back(i);
            }
        }

        // Perform Topological Sort
        // Form InDegree Array
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto itr : adjInverse[i])
            {
                inDegree[itr]++;
            }
        }

        queue<int> nodes;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                nodes.push(i);
            }
        }

        vector<int> safeNodes;
        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();
            safeNodes.push_back(node);

            for (auto itr : adjInverse[node])
            {
                inDegree[itr]--;
                if (inDegree[itr] == 0)
                {
                    nodes.push(itr);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};