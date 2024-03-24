// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// Intuition : Perform Topo-Sort
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // Form InDegree Array
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto itr : adj[i])
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

        int nodesTraverse = 0;
        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();
            nodesTraverse++;

            for (auto itr : adj[node])
            {
                inDegree[itr]--;
                if (inDegree[itr] == 0)
                {
                    nodes.push(itr);
                }
            }
        }

        return nodesTraverse != V;
    }
};