// https://www.geeksforgeeks.org/problems/number-of-provinces/1

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void dfsTraversal(vector<int> adj[], int node, vector<int> &visited)
    {
        visited[node] = 1;

        for (auto itr : adj[node])
        {
            if (!visited[itr])
            {
                dfsTraversal(adj, itr, visited);
            }
        }

        return;
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<int> visited(V, 0);

        vector<int> adjacent[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adjacent[i][j] == 1 && i != j)
                {
                    adjacent[i].push_back(j);
                    adjacent[j].push_back(i);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                count++;
                dfsTraversal(adjacent, i, visited);
            }
        }

        return count;
    }
};