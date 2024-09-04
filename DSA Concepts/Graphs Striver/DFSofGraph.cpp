// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void dfs(int node, vector<int> adj[], vector<int> &graph, vector<int> &visited)
    {
        graph.push_back(node);

        for (auto itr : adj[node])
        {
            if (!visited[itr])
            {
                visited[itr] = 1;
                dfs(itr, adj, graph, visited);
            }
        }

        return;
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> graph;
        vector<int> visited(V, 0);
        visited[0] = 1;

        dfs(0, adj, graph, visited);

        return graph;
    }
};
