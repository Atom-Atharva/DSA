// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include <iostream>
using namespace std;
#include <vector>
#include <climits>
#include <queue>

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> adj[N];
        for (int i = 0; i < edges.size(); i++)
        {
            // Undirected Graph
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> distances(N, INT_MAX);
        distances[src] = 0;

        queue<int> nodes;
        nodes.push(src);

        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();

            for (auto itr : adj[node])
            {
                if (distances[node] + 1 < distances[itr])
                {
                    distances[itr] = distances[node] + 1;
                    nodes.push(itr);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (distances[i] == INT_MAX)
            {
                distances[i] = -1;
            }
        }

        return distances;
    }
};