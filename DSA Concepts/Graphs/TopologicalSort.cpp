// https://www.geeksforgeeks.org/problems/topological-sort/1

#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>

// Method 2: InDegree
class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // Calculate InDegree for Each Vertices
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto itr : adj[i])
            {
                inDegree[itr]++;
            }
        }

        // Push 0 (Terminal) Nodes
        queue<int> nodes;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                nodes.push(i);
            }
        }

        vector<int> order;
        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();

            order.push_back(node);

            for (auto itr : adj[node])
            {
                inDegree[itr]--;
                if (inDegree[itr] == 0)
                {
                    nodes.push(itr);
                }
            }
        }

        return order;
    }
};

// Method 1: DFS
class Solution
{
    void dfsNode(int node, vector<int> adj[], vector<int> &visited, stack<int> &nodes)
    {
        visited[node] = 1;

        for (auto itr : adj[node])
        {
            if (!visited[itr])
            {
                dfsNode(itr, adj, visited, nodes);
            }
        }
        nodes.push(node);
        return;
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        stack<int> nodes;

        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfsNode(i, adj, visited, nodes);
            }
        }

        vector<int> order;
        while (!nodes.empty())
        {
            order.push_back(nodes.top());
            nodes.pop();
        }

        return order;
    }
};