// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    // Using DFS
    bool isCyclic(int node, int V, vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited)
    {
        // Check For Visited
        if (visited[node])
        {
            if (pathVisited[node])
                return true;
            else
                return false;
        }

        visited[node] = 1;
        pathVisited[node] = 1;
        bool cycle = false;

        for (auto itr : adj[node])
        {
            cycle = cycle || isCyclic(itr, V, adj, visited, pathVisited);
        }

        pathVisited[node] = 0;
        return cycle;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, 0);
        vector<bool> pathVisited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool check = isCyclic(i, V, adj, visited, pathVisited);
                if (check)
                {
                    return true;
                }
            }
        }
        return false;
    }
};