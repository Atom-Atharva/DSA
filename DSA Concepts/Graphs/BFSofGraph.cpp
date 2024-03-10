// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        queue<int> nodes;
        nodes.push(0);
        visited[0] = 1;

        vector<int> bfs;
        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();

            bfs.push_back(node);
            for (auto itr : adj[node])
            {
                if (!visited[itr])
                {
                    nodes.push(itr);
                    visited[itr] = 1;
                }
            }
        }

        return bfs;
    }
};