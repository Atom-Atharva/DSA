// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void dfsOfGraph(int node, vector<int> adj[], vector<int> &dfs, vector<int> &visited)
    {
        // Mark Visited
        visited[node] = 1;
        dfs.push_back(node);

        // For Each Adjacent node --> Try visiting them
        for (auto itr : adj[node])
        {
            if (!visited[itr])
            {
                dfsOfGraph(itr, adj, dfs, visited);
            }
        }

        return;
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> dfs;
        vector<int> visited(V, 0);
        dfsOfGraph(0, adj, dfs, visited);

        return dfs;
    }
};