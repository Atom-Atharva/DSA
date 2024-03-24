// https://www.geeksforgeeks.org/problems/eventual-safe-states/1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
    bool findSafeNodes(int node, vector<int> adj[], vector<int> &visited, vector<int> &pathVisited, vector<int> &checkNode)
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        checkNode[node] = 0;

        for (auto itr : adj[node])
        {
            if (!visited[itr])
            {
                if (findSafeNodes(itr, adj, visited, pathVisited, checkNode) == false)
                {
                    checkNode[node] = 0;
                    return false;
                }
            }
            else if (pathVisited[itr])
            {
                checkNode[node] = 0;
                return false;
            }
        }

        checkNode[node] = 1;
        pathVisited[node] = 0;
        return true;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);

        vector<int> checkNode(V, 0);

        vector<int> safeNodes;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                findSafeNodes(i, adj, visited, pathVisited, checkNode);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (checkNode[i])
            {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};